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
int			tileX(int i, int sheetwidth)
{
	return (i * TEXWIDTH % sheetwidth);
}

int			tileY(int i, int sheetwidth)
{
	return (i * TEXWIDTH / sheetwidth * TEXHEIGHT);
}

SDL_Surface	*load_tilesheet(t_wolf *wolf)
{
	SDL_Surface		*tilesheet;
	
	if (!(tilesheet = IMG_Load("./tilesheet.png")))
		return (NULL);
	tilesheet = SDL_ConvertSurfaceFormat(tilesheet, SDL_GetWindowPixelFormat(wolf->window), 0);
	return (tilesheet);
}
