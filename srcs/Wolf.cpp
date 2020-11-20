#include "Wolf.hpp"

SDL_Rect		SDL_CreateRect(int x, int y, int w, int h)
{
	return (SDL_Rect { x, y, w, h });
}

Wolf::Wolf(void)
{
	if (!(window = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPENGL)))
		SDLdie("SDL Window creation failed: ");
	if (!(renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE)))
		SDLdie("SDL Renderer creation failed: ");
	if (!(texture = SDL_CreateTexture(renderer, SDL_GetWindowPixelFormat(window), SDL_TEXTUREACCESS_TARGET, WIN_WIDTH, WIN_HEIGHT)))
		SDLdie("SDL Texture creation failed: ");
	if (!(tiles = IMG_LoadTexture(renderer, "tilesheet.png")))
		SDLdie("Tilesheet creation failed: ");
	SDL_QueryTexture(tiles, NULL, NULL, &tilesheetWidth, NULL);
	SDL_SetWindowTitle(window, "Wolf3D");
	tilesWide = tilesheetWidth / TEXWIDTH;
	try
	{
		sound = new Sound;
		sound->loadSound("bgm.mp3");
		sound->playSound();
	}
	catch (...)
	{
		delete sound;
		handleException();
	}
	try
	{
		map.load(currentmap);
		player.spawn(map);
	}
	catch (...)
	{
		handleException();
	}
	running = true;
}

Wolf::~Wolf() { }

void	Wolf::renderClear(void)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);
}

void	Wolf::gameLoop(void)
{
	if (input.isForward())
		player.move(FORWARD, map);
	if (input.isBackward())
		player.move(BACKWARD, map);
	if (input.isTurnRight())
		player.rotate(DEGTORAD(TURNRIGHT));
	if (input.isTurnLeft())
		player.rotate(DEGTORAD(TURNLEFT));
	if (input.isStrafeRight())
		player.strafe(STRAFERIGHT, map);
	if (input.isStrafeLeft())
		player.strafe(STRAFELEFT, map);
	if (input.isInteract())
		player.interact(map);
	player.setSprint(input.isSprint());

	playerInfo info = player.getInfo();
	if (map.getPoint(info.posX, info.posY) == ELEVATOR)
		nextMap();
}

void	Wolf::nextMap(void) 
{
	try
	{
		++currentmap;
		if (currentmap > NUMMAPS)
		{
			SDL_ShowSimpleMessageBox(0, "Nice!", "You Won!", window);
			running = false;
		}
		map.load(currentmap);
		player.spawn(map);
	}
	catch (...)
	{
		handleException();
	}
}

void	Wolf::raycast(int x, playerInfo &info, raycastHit &ray)
{
	double cameraX = x / (WIN_WIDTH / 2) - 1;	//convert screen coordinate to location in screen space
	bool hit = false;	//did the ray hit anything?
	int side;	//did we hit an X side or a Y side of the wall

	int mapX = static_cast<int>(info.posX);
	int	mapY = static_cast<int>(info.posY);

	double rayDirX = info.dirX + info.planeX * cameraX;
	double rayDirY = info.dirY + info.planeY * cameraX;

	//length of ray from one x or y-side to next x or y-side
	double deltaDistX = std::abs(1 / rayDirX);
	double deltaDistY = std::abs(1 / rayDirY);

	//length of ray from current position to next x or y-side
	double sideDistX = rayDirX < 0 ? (info.posX - mapX) * deltaDistX : (mapX + 1.0 - info.posX) * deltaDistX;
	double sideDistY = rayDirY < 0 ? (info.posY - mapY) * deltaDistY : (mapY + 1.0 - info.posY) * deltaDistY;

	//what direction to step in x or y-direction (either +1 or -1)
	int stepX = rayDirX < 0 ? -1 : 1;
	int stepY = rayDirY < 0 ? -1 : 1;

	while (hit == false)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		//Check if ray has hit a wall
		if (map.getPoint(mapX, mapY) > 0)
			hit = 1;
		ray.intersectTile = map.getPoint(mapX, mapY);
		if (side == 0)
			ray.perpWallDist = (mapX - info.posX + (1 - stepX) / 2) / info.dirX;
		else
			ray.perpWallDist = (mapY - info.posY + (1 - stepY) / 2) / info.dirY;
		ray.side = side;
	}

}

SDL_Rect	Wolf::getSrcPixel(Ray &ray, playerInfo &info)
{
	SDL_Rect ret;
	int tile = 0;
	tile = ray.getIntersectTile();
	int side = ray.getSide();
	int texX; //X value of pixel within tile square
	int texID = ray.getSide() ? (tile - 1) * 2 : (tile - 1) * 2 + 1; //get shaded version or not based on side
	double wallX = side ? info.posX + ray.getPerpWallDist() * ray.getDirX() : //exact X coord of contact with wall, if hitting a Y side, use Xpos
		info.posY + ray.getPerpWallDist() * ray.getDirY(); //if hitting X side, use Ypos
	wallX -= floor(wallX); //reduce it to just the location in relation to the single tile (0 for the leftmost side, 1 for the rightmost side)
	texX = static_cast<int>(wallX * TEXWIDTH);
	if ((side == 0 && ray.getDirX() > 0) || (side == 1 && ray.getDirY() < 0))
		texX = TEXWIDTH - texX - 1; //in either of these cases, we need to invert texX as heading from left to right on a tile decreases wallX instead of increasing
	ret = { ((texID % tilesWide) * TEXWIDTH) + texX, (texID / tilesWide) * TEXHEIGHT, 1, 64 }; //get actual XY of column on tilesheet
	return ret;
}
void	Wolf::render(void)
{
	playerInfo info = player.getInfo();
	Ray ray;
	double cameraX;
	int lineHeight; //height of line to draw on screen
	int drawStart; //Y location to start drawing
	SDL_Rect destRect; //contains the location of where we're drawing the pixel to the screen

	//SDL_LockTexture(wolf->texture->tex, NULL, &wolf->texture->data, &wolf->texture->pitch);
	//wolf->texture->pixels = (Uint32*)wolf->texture->data;
	SDL_SetRenderTarget(renderer, texture); 
	SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
	SDL_RenderFillRect(renderer, &SDL_CreateRect(0, 0, WIN_WIDTH, WIN_HEIGHT / 2)); //draw ceiling
	SDL_SetRenderDrawColor(renderer, 102, 102, 102, 255);
	SDL_RenderFillRect(renderer, &SDL_CreateRect(0, WIN_HEIGHT / 2, WIN_WIDTH, WIN_HEIGHT / 2)); //draw floor
	for (int x = 0; x < WIN_WIDTH; x++)
	{
		cameraX = x / (WIN_WIDTH / 2.0) - 1;
		if (cameraX == 0.0)
			int j = 0;
		ray.dda(x, info, map);
		lineHeight = static_cast<int>(WIN_HEIGHT / ray.getPerpWallDist());
		drawStart = (WIN_HEIGHT - lineHeight) / 2;
		//drawStart = drawStart < 0 ? 0 : drawStart; //check if we'd start drawing offscreen and correct
		destRect = { x, drawStart, 1, lineHeight };
		SDL_Rect tileRect = getSrcPixel(ray, info);
		SDL_RenderCopy(renderer, tiles, &tileRect, &destRect); //getSrcPixel gets the SDL_Rect for the pixel we're copying
	}
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	//minimap(wolf);
	SDL_RenderPresent(renderer);
}



bool Wolf::isRunning(void) { return running; }
gameMap& Wolf::getMap(void) { return map; }
Input&	Wolf::getInput(void) { return input; }
void	Wolf::exit(void) { running = false; }


void	handleException(void)
{
	try {
		throw;
	}
	catch (std::exception& e)
	{
		e.what();
	}
}