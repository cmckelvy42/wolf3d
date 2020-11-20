#include "Ray.hpp"

void	Ray::dda(int x, playerInfo info, gameMap &map)
{
	double cameraX = 2.0f * x / WIN_WIDTH - 1;	//convert screen coordinate to location in screen space
	bool hit = false;	//did the ray hit anything?

	mapLocX = static_cast<int>(info.posX);
	mapLocY = static_cast<int>(info.posY);

	dirX = info.dirX + info.planeX * cameraX;
	dirY = info.dirY + info.planeY * cameraX;

	//length of ray from one x or y-side to next x or y-side
	deltaDistX = std::abs(1 / dirX);
	deltaDistY = std::abs(1 / dirY);

	//length of ray from current position to next x or y-side
	sideDistX = dirX < 0 ? (info.posX - mapLocX) * deltaDistX : (mapLocX + 1.0 - info.posX) * deltaDistX;
	sideDistY = dirY < 0 ? (info.posY - mapLocY) * deltaDistY : (mapLocY + 1.0 - info.posY) * deltaDistY;

	//what direction to step in x or y-direction (either +1 or -1)
	stepX = dirX < 0 ? -1 : 1;
	stepY = dirY < 0 ? -1 : 1;

	while (hit == false)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapLocX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapLocY += stepY;
			side = 1;
		}
		//Check if ray has hit a wall
		if (map.getPoint(mapLocX, mapLocY) > 0)
			hit = 1;
	}
		intersectTile = map.getPoint(mapLocX, mapLocY);
		if (side == 0)
			perpWallDist = (mapLocX - info.posX + (1 - stepX) / 2) / dirX;
		else
			perpWallDist = (mapLocY - info.posY + (1 - stepY) / 2) / dirY;
}

int	Ray::getIntersectTile(void) { return intersectTile; }
double	Ray::getDirX(void) { return dirX; }
double	Ray::getDirY(void) { return dirY; }
double	Ray::getPerpWallDist(void) { return perpWallDist; }
int		Ray::getSide(void) { return side; }