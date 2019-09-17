/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:25:32 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/09/10 15:39:28 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		clear_image(t_image *image)
{
	ft_bzero(image->ptr, WIN_WIDTH * WIN_HEIGHT * image->bpp);
}

t_point		*set_point(t_map *map, int x, int y, char *str)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	if (!point)
		return (NULL);
	if (*str < '0' || *str > '9')
		die("Invalid map.");
	point->x = x;
	point->y = y;
	point->tile = ft_atoi(str);
	if (point->tile > NUMTILES || point->tile < 0)
		die("Invalid map.");
	if (point->x == 0 || point->y == 0
	|| point->x == map->width - 1 || point->y == map->height - 1)
		if (!(point->tile))
			die("Invalid map.");
	return (point);
}

void		die(const char *str)
{
	ft_putendl(str);
	exit(1);
}

int			game(t_wolf *wolf)
{
	render(wolf);
	return (0);
}

int			main(void)
{
	t_wolf		*wolf;
	int			fd;
	int			i;

	if (!(wolf = (t_wolf*)ft_memalloc(sizeof(t_wolf))))
		die("Malloc error.");
	if (!(wolf->player = (t_player*)ft_memalloc(sizeof(t_player))))
		die("Malloc error.");
	wolf->map = (t_map**)ft_memalloc(sizeof(t_map*) * NUMMAPS);
	i = 1;
	while (i <= NUMMAPS)
	{
		if ((fd = open_map(i)) < 0)
			die("A map is missing!");
		if (!(read_file(fd, &wolf->map[i - 1])))
			die("invalid map");
		i++;
	}
	init(wolf);
	mlx_loop_hook(wolf->mlx, game, wolf);
	mlx_hook(wolf->window, 2, 0, key_hook, wolf);
	mlx_hook(wolf->window, 17, 0, ft_close, wolf);
	mlx_loop(wolf->mlx);
	return (0);
}
