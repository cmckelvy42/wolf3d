#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP
#include <vector>
#include "mapPoint.hpp"
#include "shared.hpp"
#include <string>
#include <fstream>
#include <iostream>

class gameMap
{
private:
	int					width;
	int					height;
	std::vector<int>	points;
	int					door; //door mapPoint index for instant find later, populated on map load
	void				splitLine(std::string line);
public:
	gameMap() = default;
	~gameMap() = default;
	void				load(int i);
	int					getHeight();
	int					getWidth();
	int					getPoint(int x, int y);
	void				openDoor(void);
	void				setPoint(int x, int y, int n);

};
#endif
