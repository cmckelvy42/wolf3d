#ifndef W_PLAYER_HPP
#define W_PLAYER_HPP
#include "shared.hpp"
#include "gameMap.hpp"

struct	playerInfo
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
};
typedef struct playerInfo playerInfo;

class Player
{
private:
	playerInfo					info = { 0.0, 0.0, 1.0, 0.0, 0.0, 2.0 / 3.0f };
	bool						sprint = false;
public:
	Player(void) = default;
	~Player(void) = default;

	void		rotate(float angle);
	void		move(float distance, gameMap &map);
	void		strafe(float distance, gameMap &map);
	void		spawn(gameMap &map);
	void		interact(gameMap &map);
	playerInfo	getInfo(void);
	void		setSprint(bool b);
};

#endif
