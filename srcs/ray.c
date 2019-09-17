/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 01:14:56 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/09/09 18:04:40 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_ray	init_ray(t_wolf *wolf, t_vector dir)
{
	t_ray	ray;

	ray.map.x = (int)wolf->player->pos.x;
	ray.map.y = (int)wolf->player->pos.y;
	ray.deltadist.x = fabs(1.0 / dir.x);
	ray.deltadist.y = fabs(1.0 / dir.y);
	ray.step.x = (dir.x < 0) ? -1 : 1;
	ray.step.y = (dir.y < 0) ? -1 : 1;
	ray.sidedist.x = ray.deltadist.x * ((dir.x < 0) ?
		wolf->player->pos.x - ray.map.x :
		ray.map.x + 1.0 - wolf->player->pos.x);
	ray.sidedist.y = ray.deltadist.y * ((dir.y < 0) ?
		wolf->player->pos.y - ray.map.y :
		ray.map.y + 1.0 - wolf->player->pos.y);
	ray.hit = 0;
	return (ray);
}

void	dda(t_wolf *wolf, t_ray *ray, t_vector dir)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (wolf->map[wolf->currentmap]->points[(int)ray->map.x +
			((int)ray->map.y * wolf->map[wolf->currentmap]->width)]->tile)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->map.x - wolf->player->pos.x +
			(1 - ray->step.x) / 2) / dir.x;
	else
		ray->perpwalldist = (ray->map.y - wolf->player->pos.y +
			(1 - ray->step.y) / 2) / dir.y;
}

int		texture_pixel(t_wolf *wolf, t_ray ray, t_vector dir, int y)
{
	int		texid;
	double	wallx;
	int		texx;
	int		texy;

	texid = (wolf->map[wolf->currentmap]->points[xy_to_point(wolf,
	(int)ray.map.x, (int)ray.map.y)]->tile - 1) * 2;
	if (!ray.side && ray.map.x > wolf->player->pos.x)
		texid++;
	else if (ray.side)
	{
		texid += 2;
		if (ray.map.y > wolf->player->pos.y)
			texid++;
	}
	wallx = ray.side == 0 ? wolf->player->pos.y + ray.perpwalldist * dir.y :
		wolf->player->pos.x + ray.perpwalldist * dir.x;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)TEXWIDTH);
	if ((ray.side == 0 && dir.x > 0) || (ray.side == 1 && dir.y < 0))
		texx = TEXWIDTH - texx - 1;
	texy = (((double)y - (WIN_HEIGHT - ray.height) / 2) / ray.height *
		wolf->tiles[texid]->height);
	return (get_pixel(wolf->tiles[texid], texx, texy));
}

void	draw_ray(t_wolf *wolf, t_vector dir, int x)
{
	t_ray	ray;
	int		drawstart;
	int		drawend;

	ray = init_ray(wolf, dir);
	dda(wolf, &ray, dir);
	ray.height = (int)(WIN_HEIGHT / ray.perpwalldist);
	drawstart = (WIN_HEIGHT - ray.height) / 2;
	drawstart = drawstart < 0 ? 0 : drawstart;
	drawend = (WIN_HEIGHT + ray.height) / 2;
	drawend = drawend >= WIN_HEIGHT ? WIN_HEIGHT - 1 : drawend;
	while (drawstart < drawend)
	{
		image_set_pixel(wolf->image, x, drawstart,
			texture_pixel(wolf, ray, dir, drawstart));
		drawstart++;
	}
}
