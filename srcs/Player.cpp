/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:14:11 by rsmith            #+#    #+#             */
/*   Updated: 2019/09/05 22:01:26 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

void	Player::rotate(float angle)
{
	float	cosine;
	float	sine;
	double oldDirX = info.dirX;
	double oldPlaneX = info.planeX;

	
	cosine = cos(angle);
	sine = sin(angle);
	info.dirX = info.dirX * cosine - info.dirY * sine;
	info.dirY =  oldDirX * sine + info.dirY * cosine;
	info.planeX = info.planeX * cosine - info.planeY * sine;
	info.planeY = oldPlaneX * sine + info.planeY * cosine;
}

void	Player::move(float distance, gameMap &map)
{
	double moveX = distance * info.dirX;
	double moveY = distance * info.dirY;

	if (!map.getPoint(info.posX + moveX * 25, info.posY) || map.getPoint(info.posX + moveX * 25, info.posY) == ELEVATOR)
		info.posX += moveX * (sprint ? 5.0 : 1.0);
	if (!map.getPoint(info.posX, info.posY + moveY * 25) || map.getPoint(info.posX, info.posY + moveY * 25) == ELEVATOR)
		info.posY += moveY * (sprint ? 5.0 : 1.0);
}

void	Player::strafe(float distance, gameMap &map)
{
	float cosine = cos(DEGTORAD(90));
	float sine = sin(DEGTORAD(90));
	double moveX = distance * (info.dirX * cosine - info.dirY * sine);
	double moveY = distance * (info.dirX * sine + info.dirY * cosine);

	if (!map.getPoint(info.posX + moveX * 25,info.posY) || map.getPoint(info.posX + moveX * 25, info.posY) == ELEVATOR)
		info.posX += moveX * (sprint ? 5.0 : 1.0);
	if (!map.getPoint(info.posX, info.posY + moveY * 25) || map.getPoint(info.posX, info.posY + moveY * 25) == ELEVATOR)
		info.posY += moveY * (sprint ? 5.0 : 1.0);
}

void	Player::interact(gameMap &map)
{
	if (map.getPoint(info.posX + info.dirX, info.posY + info.dirY) == SWITCH)
	{
		map.setPoint(info.posX + info.dirX, info.posY + info.dirY, FLIPPED);
		map.openDoor();
	}
	else if (map.getPoint(info.posX + info.dirX, info.posY + info.dirY) == SECRET)
		map.setPoint(info.posX + info.dirX, info.posY + info.dirY, 0);
}

void	Player::spawn(gameMap &map)
{
	int		x;
	int		y;
	int		w = map.getWidth();
	int		h = map.getHeight();

	for(int i = 0; i < h * w; i++)
	{
		y = i / w;
		x = i % w;
		if (!map.getPoint(x, y))
			break;
	}

	if (x == 0 || x == w || y == 0 || y == h)
		throw(std::runtime_error("Invalid map - No valid empty tiles"));
	info.posX = x + 0.5f;
	info.posY = y + 0.5f;
}

void		Player::setSprint(bool b) { if (sprint != b) sprint = b; }
playerInfo	Player::getInfo(void) { return info; }
