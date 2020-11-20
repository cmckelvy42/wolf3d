#ifndef WOLF_HPP
#define WOLF_HPP
#include "gameMap.hpp"
#include "Player.hpp"
#include "Input.hpp"
#include "shared.hpp"
#include "Ray.hpp"
#include "Sound.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <fstream>
#include <vector>

struct raycastHit
{
	double				perpWallDist;
	int					side;
	int					intersectTile;
};

class Wolf
{
private:
	SDL_Window					*window;
	SDL_Renderer				*renderer;
	gameMap						map;
	Player						player;
	Input						input;
	SDL_Texture					*tiles;
	int							tilesheetWidth;
	int							tilesWide; //how many tiles in each row of tilesheet
	char						currentmap = 1; //should never need to count past 256 maps lmao
	SDL_Texture					*texture;
	Sound						*sound;
	bool						running = false;
	std::pair<double, double>	pos = { 0, 0 };
	std::pair<double, double>	dir = { 1.0f, 0 };
	std::pair<double, double>	plane = { 0., 2.0f / 3.0f };
	SDL_Rect					getSrcPixel(Ray &ray, playerInfo &info);
	void						raycast(int x, playerInfo &info, raycastHit &ray);
public:
	Wolf(void);
	~Wolf(void);
	void						renderClear(void);
	void						gameLoop(void);
	Input&						getInput(void);
	gameMap&					getMap(void);
	void						nextMap(void);
	bool						isRunning(void);
	void						exit(void);
	void						render(void);
};

void	handleException(void);
#endif
