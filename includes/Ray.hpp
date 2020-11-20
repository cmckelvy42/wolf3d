
#ifndef RAY_HPP
#define RAY_HPP
#include <utility>
#include <SDL.h>
#include "shared.hpp"
#include "Player.hpp"

class Ray
{
private:
	double				deltaDistX;
	double				deltaDistY;
	double				dirX;
	double				dirY;
	double				perpWallDist;
	double				sideDistX;
	double				sideDistY;
	int					mapLocX;
	int					mapLocY;
	int					stepX;
	int					stepY;
	int					side; //did we hit an X side or a Y side of the wall
	int					intersectTile;
public:
	Ray(void) = default;
	~Ray(void) = default;
	void	dda(int x, playerInfo info, gameMap &map);
	double	getDirX(void);
	double	getDirY(void);
	double	getPerpWallDist(void);
	int		getSide(void);
	int		getIntersectTile(void);
	
};

#endif
