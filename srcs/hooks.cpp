/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:14:18 by rsmith            #+#    #+#             */
/*   Updated: 2019/09/10 21:11:39 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

int		action_two(Player &player)
{
	if (player.getMap().getPoint((int)(player.getX() + player->dir.x), (int)wolf->player->pos.y) == ELEVATOR)
	{
		wolf->currentmap++;
		if (wolf->currentmap == NUMMAPS)
			die("You won!");
		iniPlayer(wolf->player, wolf->map[wolf->currentmap]);
	}
	else if (get_tile(wolf->map[wolf->currentmap], (int)wolf->player->pos.x,
		(wolf->player->pos.y + 1.0f * wolf->player->dir.y)) == ELEVATOR)
	{
		wolf->currentmap++;
		if (wolf->currentmap == NUMMAPS)
			die("You won!");
		iniPlayer(wolf->player, wolf->map[wolf->currentmap]);
	}
	else if (get_tile(wolf->map[wolf->currentmap], (int)(wolf->player->pos.x
	+ 1.0f * wolf->player->dir.x), (int)wolf->player->pos.y) == SECRET)
		open_door(wolf, SECRET);
	else if (get_tile(wolf->map[wolf->currentmap], (int)wolf->player->pos.x,
		(wolf->player->pos.y + 1.0f * wolf->player->dir.y)) == SECRET)
		open_door(wolf, SECRET);
	return (0);
}

int		action_key(Player &player)
{
	if (player.getMap().getPoint((int)(player.getX() + 1.0f *
		player.getDir.x), (int)wolf->player->pos.y) == SWITCH)
	{
		wolf->map[wolf->currentmap]->points[(int)(wolf->player->pos.x +
		1.0f * wolf->player->dir.x) + ((int)wolf->player->pos.y *
		wolf->map[wolf->currentmap]->width)]->tile = FLIPPED;
		open_door(wolf, DOOR);
	}
	else if (get_tile(wolf->map[wolf->currentmap], (int)wolf->player->pos.x,
		(wolf->player->pos.y + 1.0f * wolf->player->dir.y)) == SWITCH)
	{
		wolf->map[wolf->currentmap]->points[(int)wolf->player->pos.x +
		(int)((wolf->player->pos.y + 1.0f * wolf->player->dir.y) *
		wolf->map[wolf->currentmap]->width)]->tile = FLIPPED;
		open_door(wolf, DOOR);
	}
	else
		action_two(wolf);
	return (0);
}

void		key_hook(Wolf *wolf)
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			SDL_Quit();
			IMG_Quit();
			exit(1);
		}
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				exit(0);
			if (event.key.keysym.sym == SDLK_z)
				wolf->player->spd = wolf->player->spd == 1 ? 5 : 1;
			if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a)
				player_rotate(wolf->player, -5.0f / 180.0f * 3.14159265358979323846);
			if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)
				player_rotate(wolf->player, 5.0f / 180.0f * 3.14159265358979323846);
			if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_UP)
				player_move(wolf->player, wolf->map[wolf->currentmap],
				(0.1f * wolf->player->spd));
			if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)
				player_move(wolf->player, wolf->map[wolf->currentmap],
				(-0.1f * wolf->player->spd));
			if (event.key.keysym.sym == SDLK_SPACE)
				action_key(wolf);
			if (event.key.keysym.sym == SDLK_e)
				player_strafe(wolf)
			if (event.key.keysym.sym == SDLK_q)
			{
				wolf->player->pos.x -= wolf->player->plane.x * (0.1f * wolf->player->spd);
				wolf->player->pos.y -= wolf->player->plane.y * (0.1f * wolf->player->spd);
			}
		}
		return ;
	}
}
