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

#include "wolf.h"

void	init(t_wolf *wolf)
{
	t_sound	*sound;

	sound = initsound();
	wolf->player->spd = 1;
	wolf->currentmap = 0;
	init_player(wolf->player, wolf->map[0]);
	wolf->window = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPENGL);
	wolf->renderer = SDL_CreateRenderer(wolf->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	wolf->texture = ft_memalloc(sizeof(t_exture));
	wolf->texture->tex = SDL_CreateTexture(wolf->renderer, SDL_GetWindowPixelFormat(wolf->window), SDL_TEXTUREACCESS_STREAMING, WIN_WIDTH, WIN_HEIGHT);
	wolf->tiles = load_tilesheet(wolf);
	SDL_SetWindowTitle(wolf->window, "Wolf3D");
	loadsound(sound, "bgm.mp3");
	playsound(sound, 0);
	free(sound);
	return ;
}

int		ft_close(void)
{
	exit(1);
	return (0);
}

int		xy_to_point(t_wolf *wolf, int x, int y)
{
	return (x + (y * wolf->map[wolf->currentmap]->width));
}

/* void	minimap(t_wolf *wolf)
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

int		open_map(int i)
{
	int		fd;
	char	*file;
	char	*index;

	CHECK_BAD(!(index = ft_itoa(i)));
	CHECK_BAD(!(file = ft_strnew(7 + ft_strlen(index))));
	file = ft_strcat(file, "map");
	file = ft_strcat(file, index);
	file = ft_strcat(file, ".map");
	if ((fd = open(file, O_RDONLY)) <= 0)
		return (-1);
	ft_strdel(&file);
	ft_strdel(&index);
	return (fd);
}
