/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:25:53 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/09/10 14:41:31 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_SHARED_H
#define W_SHARED_H

#define DOOR 50
#define SWITCH 22
#define FLIPPED 21
#define SECRET 33
#define ELEVATOR 51
#define TEXWIDTH 64
#define DEGTORAD(x) (x * M_PI / 180)
#define TEXHEIGHT 64
#define WIN_WIDTH 840
#define WIN_HEIGHT 660
#define NUMMAPS 3
#define FORWARD 0.01
#define BACKWARD -0.01
#define TURNRIGHT 1.0
#define TURNLEFT -1.0
#define STRAFERIGHT 0.01
#define STRAFELEFT -0.01
#define _USE_MATH_DEFINES
#include <cmath>

void		SDLdie(const char *str);

#endif