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

#ifndef WOLF_H
# define WOLF_H

# define DOOR 50
# define SWITCH 22
# define FLIPPED 21
# define ELEVATOR 51
# define SECRET 33
# define THREADS 1
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define WIN_WIDTH 840
# define WIN_HEIGHT 660
# define NUMTILES 57
# define NUMMAPS 3
# define CHECK_BAD(x)			if (x) return (-1)

# include "../libft/includes/libft.h"
# include <math.h>
# include <pthread.h>
# include "../fmod/fmod.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

typedef struct			s_point
{
	int					x;
	int					y;
	int					tile;
	char				*value;
}						t_point;

typedef struct			s_map
{
	int					width;
	int					height;
	t_point				**points;
}						t_map;

typedef struct			s_vector
{
	double				x;
	double				y;
}						t_vector;

typedef struct			s_yaboi
{
	t_vector			map;
	t_vector			sidedist;
	t_vector			deltadist;
	double				perpwalldist;
	t_vector			step;
	int					hit;
	int					side;
	int					height;
	SDL_Surface			*texture;
}						t_ray;

typedef struct			s_player
{
	t_vector			pos;
	t_vector			dir;
	t_vector			plane;
	int					spd;
}						t_player;

typedef struct			s_texture
{
	SDL_Texture			*tex;
	void				*data;
	int					pitch;
	Uint32				*pixels;
}						t_exture;

typedef struct			s_wolf
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	t_map				**map;
	t_player			*player;
	SDL_Surface			*tiles;
	int					currentmap;
	t_exture			*texture;
}						t_wolf;

typedef struct			s_thread
{
	t_wolf				*wolf;
	int					x;
	pthread_t			thread;
}						t_thread;

typedef struct			s_ound
{
	int					on;
	int					possible;
	char				*currentsound;
	FMOD_RESULT			result;
	FMOD_SYSTEM			*fmodsystem;
	FMOD_SOUND			*sound;
	FMOD_CHANNEL		*channel;
	FMOD_CHANNELGROUP	*music;
}						t_sound;

void					playsound(t_sound *sound, int pause);
void					loadsound(t_sound *sound, const char *filename);
int						read_file(int fd, t_map **map);
void					render(t_wolf *wolf);
void					draw_ray(t_wolf *wolf, t_vector dir, int x);
int						get_tile(t_map *map, int x, int y);
void					init_player(t_player *player, t_map *map);
void					player_rotate(t_player *player, float angle);
void					player_move(t_player *player, t_map *map,
						float distance);
SDL_Surface				*load_tilesheet(t_wolf *wolf);
int			tileX(int i, int sheetwidth);
int			tileY(int i, int sheetwidth);
t_point					*set_point(t_map *map, int x, int y, char *str);
void					die(const char *str);
int						ft_close(void);
int						xy_to_point(t_wolf *wolf, int x, int y);
void					minimap(t_wolf *wolf);
void					init(t_wolf *wolf);
void					key_hook(t_wolf *wolf);
t_sound					*initsound(void);
int						open_map(int i);
Uint32					surface_get_pixel(SDL_Surface *image, int x, int y);
void					surface_set_pixel(SDL_Surface *image, int x, int y, Uint32 pixel);

#endif
