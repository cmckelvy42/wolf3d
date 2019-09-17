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

void		*draw_thread(void *thread)
{
	t_wolf		*wolf;
	int			x;
	double		camera;
	t_vector	dir;

	wolf = (t_wolf*)((t_thread*)thread)->wolf;
	x = ((t_thread*)thread)->x;
	while (x < WIN_WIDTH)
	{
		camera = 2.0f * x / WIN_WIDTH - 1;
		dir.x = wolf->player->dir.x + wolf->player->plane.x * camera;
		dir.y = wolf->player->dir.y + wolf->player->plane.y * camera;
		draw_ray(wolf, dir, x);
		x += THREADS;
	}
	return (NULL);
}

static void	untex_floorceiling(t_image *image)
{
	int x;
	int y;
	int color;

	y = 0;
	color = 0x222222;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		if (y > WIN_HEIGHT / 2 && color != 0x666666)
			color = 0x666666;
		while (x < WIN_WIDTH)
		{
			image_set_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}

void		image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= image->width || y < 0 || y >= image->height)
		return ;
	*(int*)(image->ptr + ((x + y * image->width) * image->bpp)) = color;
}

int			get_pixel(t_image *image, int x, int y)
{
	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return (0);
	return (*(int *)(image->ptr + ((x + y * image->width)
			* image->bpp)));
}

void		render(t_wolf *wolf)
{
	int			x;
	int			i;
	t_thread	threads[THREADS];

	i = 0;
	x = 0;
	untex_floorceiling(wolf->image);
	while (i < THREADS)
	{
		threads[i].x = i;
		threads[i].wolf = wolf;
		pthread_create(&(threads[i]).thread, NULL, draw_thread, &threads[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i++].thread, NULL);
		minimap(wolf);
	}
	mlx_put_image_to_window(wolf, wolf->window, wolf->image->image, 0, 0);
}
