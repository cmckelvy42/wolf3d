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

#include "wolf.h"

int		get_tile(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (0);
	return (map->points[x + (y * map->width)]->tile);
}

void	init_player(t_player *player, t_map *map)
{
	int		x;
	int		y;
	int		z;

	y = 0;
	z = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!(z = get_tile(map, x, y)))
				break ;
			x++;
		}
		y++;
		if (!z)
			break ;
	}
	if (y == map->height || x == map->width)
		die("Invalid map.");
	player->pos.x = x + 0.5f;
	player->pos.y = y + 0.5f;
	player->dir = (t_vector){1.0f, 0.0f};
	player->plane = (t_vector){0.0f, 2.0f / 3.0f};
}

void	rotate(t_vector *vector, float angle)
{
	float	x;
	float	cosine;
	float	sine;

	x = vector->x;
	cosine = cos(angle);
	sine = sin(angle);
	vector->x = vector->x * cosine - vector->y * sine;
	vector->y = x * sine + vector->y * cosine;
}

void	player_rotate(t_player *player, float angle)
{
	rotate(&player->dir, angle);
	rotate(&player->plane, angle);
}

void	player_move(t_player *player, t_map *map, float distance)
{
	if (!get_tile(map, (int)(player->pos.x + distance
		* player->dir.x), (int)player->pos.y))
		player->pos.x += distance * player->dir.x;
	if (!get_tile(map, (int)player->pos.x, (int)
		(player->pos.y + distance * player->dir.y)))
		player->pos.y += distance * player->dir.y;
}
