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
# define THREADS 10
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define WIN_WIDTH 840
# define WIN_HEIGHT 660
# define NUMTILES 57
# define NUMMAPS 3
# define CHECK_BAD(x)			if (x) return (-1)

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>
# include "../fmod/fmod.h"

typedef struct			s_image
{
	void				*image;
	char				*ptr;
	int					bpp;
	int					stride;
	int					endian;
	int					width;
	int					height;
}						t_image;

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
	t_image				*texture;
}						t_ray;

typedef struct			s_player
{
	t_vector			pos;
	t_vector			dir;
	t_vector			plane;
	int					spd;
}						t_player;

typedef struct			s_wolf
{
	void				*mlx;
	void				*window;
	t_image				*image;
	t_map				**map;
	t_player			*player;
	t_image				**tiles;
	int					currentmap;
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
int						get_pixel(t_image *image, int x, int y);
void					image_set_pixel(t_image *image, int x, int y,
						int color);
void					draw_ray(t_wolf *wolf, t_vector dir, int x);
int						get_tile(t_map *map, int x, int y);
void					init_player(t_player *player, t_map *map);
void					player_rotate(t_player *player, float angle);
void					player_move(t_player *player, t_map *map,
						float distance);
t_image					*new_image(t_wolf *wolf, int width, int height);
t_image					*del_image(t_wolf *wolf, t_image *image);
t_image					**load_tilesheet(t_wolf *wolf);
t_point					*set_point(t_map *map, int x, int y, char *str);
void					clear_image(t_image *image);
void					die(const char *str);
int						ft_close(void);
int						xy_to_point(t_wolf *wolf, int x, int y);
void					minimap(t_wolf *wolf);
void					init(t_wolf *wolf);
int						key_hook(int key, t_wolf *wolf);
t_sound					*initsound(void);
int						open_map(int i);

#endif
