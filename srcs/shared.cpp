/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normsucks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:38:56 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/09/10 15:31:33 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.hpp"



/* void	minimap(Wolf *wolf)
{
	int	x;
	int	y;
	int current;
	int	tile;

	current = wolf->currentmap;
	y = 0;
	while (y < wolf->map[current]->height)
	{
		x = 0;
		while (x < wolf->map[current]->width)
		{
			tile = wolf->map[current]->points[xy_to_point(wolf, x, y)]->tile;
			if (tile == SWITCH)
				surface_set_pixel(wolf->surface, x * 7 + 10, y * 7 + 10, 0x0EC6F1);
			else if (tile == ELEVATOR || tile == DOOR)
				surface_set_pixel(wolf->surface, x * 7 + 10, y * 7 + 10, 0xFF0000);
			else if (tile)
				surface_set_pixel(wolf->surface, x * 7 + 10, y * 7 + 10, 0xFFFFFF);
			x++;
		}
		y++;
	}
	surface_set_pixel(wolf->surface, wolf->player->pos.x * 7 + 10,
		wolf->player->pos.y * 7 + 10, 0x00FF00);
} */


