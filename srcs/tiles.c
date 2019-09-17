/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:26:23 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/09/07 00:41:49 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_image	*new_image(t_wolf *wolf, int width, int height)
{
	t_image *image;

	if (!(image = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(image->image = mlx_new_image(wolf->mlx, width, height)))
		return (del_image(wolf, image));
	image->ptr = mlx_get_data_addr(image->image, &image->bpp, &image->stride,
			&image->endian);
	image->bpp /= 8;
	image->height = height;
	image->width = width;
	return (image);
}

t_image	*del_image(t_wolf *wolf, t_image *image)
{
	if (image != NULL)
	{
		if (image->image)
			mlx_destroy_image(wolf->mlx, image->image);
		ft_memdel((void**)&image);
	}
	return (NULL);
}

t_image	*new_image_from_xpm(t_wolf *wolf, char *xpm)
{
	t_image	*tile;
	int		width;
	int		height;

	if (!(tile = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(tile->image =
		mlx_xpm_file_to_image(wolf->mlx, xpm, &width, &height)))
		return (del_image(wolf, tile));
	tile->ptr = mlx_get_data_addr(tile->image, &tile->bpp, &tile->stride,
			&tile->endian);
	tile->bpp /= 8;
	tile->width = width;
	tile->height = height;
	return (tile);
}

void	split_sheet(t_image *tilesheet, t_image *tile, int i)
{
	int x;
	int y;
	int startx;
	int starty;

	y = 0;
	startx = (i * TEXWIDTH) % tilesheet->width;
	starty = TEXHEIGHT * ((i * TEXWIDTH) / tilesheet->width);
	while (y < TEXHEIGHT)
	{
		x = 0;
		while (x < TEXHEIGHT)
		{
			image_set_pixel(tile, x, y,
				get_pixel(tilesheet, x + startx, y + starty));
			x++;
		}
		y++;
	}
}

t_image	**load_tilesheet(t_wolf *wolf)
{
	t_image	**tiles;
	t_image	*tilesheet;
	int		i;
	int		numtiles;

	i = 0;
	if (!(tilesheet = new_image_from_xpm(wolf, "tilesheet.xpm")))
		return (NULL);
	numtiles = (tilesheet->width / TEXWIDTH) * (tilesheet->height / TEXHEIGHT);
	if (!(tiles = ft_memalloc(sizeof(t_image*) * numtiles)))
		return (NULL);
	while (i < numtiles)
	{
		if (!(tiles[i] = new_image(wolf, TEXWIDTH, TEXHEIGHT)))
			return (NULL);
		split_sheet(tilesheet, tiles[i], i);
		i++;
	}
	del_image(wolf, tilesheet);
	return (tiles);
}
