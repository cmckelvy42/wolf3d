/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:14:57 by rsmith            #+#    #+#             */
/*   Updated: 2019/09/09 17:46:37 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		*draw_thread(t_wolf *wolf)
{
	int			x;
	double		camera;
	t_vector	dir;

	x = 0;
	while (x < WIN_WIDTH)
	{
		camera = 2.0f * x / WIN_WIDTH - 1;
		dir.x = wolf->player->dir.x + wolf->player->plane.x * camera;
		dir.y = wolf->player->dir.y + wolf->player->plane.y * camera;
		draw_ray(wolf, dir, x);
		x++;
	}
	return (NULL);
}

  static void	untex_floorceiling(t_exture *texture)
{
	int 	x;
	int 	y;
	int 	color;

	color = 0x222222;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		if (y > WIN_HEIGHT / 2 && color == 0x222222)
		{
			color = 0x666666;
		}
		while (x < WIN_WIDTH)
		{
			texture->pixels[x + y * (texture->pitch / 4)] = color;
			x++;
		}
		y++;
	}
} 

void		render(t_wolf *wolf)
{
	SDL_LockTexture(wolf->texture->tex, NULL, &wolf->texture->data, &wolf->texture->pitch);
	wolf->texture->pixels = (Uint32*)wolf->texture->data;
	untex_floorceiling(wolf->texture);
	draw_thread(wolf);
	SDL_UnlockTexture(wolf->texture->tex);
	SDL_RenderCopy(wolf->renderer, wolf->texture->tex, NULL, NULL);
	 	//minimap(wolf);
	SDL_RenderPresent(wolf->renderer);
}
