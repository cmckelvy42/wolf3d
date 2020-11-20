#include "gameMap.hpp"


void gameMap::load (int i)
{
	std::string str = "map" + std::to_string(i) + ".map";
	std::ifstream file(str);
	std::vector<std::string> lines;
	
	points.clear();
	if (file.is_open())
	{
		while (std::getline(file, str))
		{
			lines.push_back(str);
			if (std::count(lines[lines.size() - 1].begin(), lines[lines.size() - 1].end(), ' ') != std::count(lines[0].begin(), lines[0].end(), ' ')) //ensure width is consistent
				throw(std::runtime_error("Invalid map: inconsistent width"));
		}
		file.close();
	}
	else throw std::runtime_error("error opening map file!");
	width = std::count(lines[0].begin(), lines[0].end(), ' ') + 1;
	height = lines.size();
	for (int i = 0; i < lines.size(); ++i)
		splitLine(lines[i]);
	door = std::find(points.begin(), points.end(), DOOR) - points.begin();
}

void					gameMap::splitLine(std::string line)
{
	std::size_t start = 0;
	std::size_t end;
	while (start < line.size())
	{
		end = std::find(line.begin() + start, line.end(), ' ') - line.begin();
		points.push_back(std::stoi(line.substr(start, end - start)));
		start = end + 1;
	}
}

void		gameMap::openDoor(void) { points[door] = ELEVATOR; }
void		gameMap::setPoint(int x, int y, int n) { points[y * width + x] = n; }

int			gameMap::getPoint(int x, int y) { return points[y * width + x]; }
int			gameMap::getHeight(void) { return height; }
int			gameMap::getWidth(void) { return width; }

