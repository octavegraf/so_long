/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:25:58 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/16 17:54:09 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include <errno.h>
# include <string.h>

typedef struct s_sprites
{
	char	*background;
	char	*empty;
	char	*wall;
	char	*exit;
	char	*player;
	char	*collectible;
	int		x;
	int		y;
}	t_sprites;


typedef struct s_data
{
	char		**map;
	int			x;
	int			y;
	int			moves;
	int			collectibles;
	void		*mlx;
	void		*win;
	t_sprites	*sprites;
}	t_data;

# define BACKGROUND_1 "./assets/background_1.xpm"
# define BACKGROUND_2 "./assets/background_2.xpm"
# define EMPTY_1 "./assets/empty_1.xpm"
# define EMPTY_2 "./assets/empty_2.xpm"
# define WALL_1 "./assets/wall_1.xpm"
# define WALL_2 "./assets/wall_2.xpm"
# define EXIT_1 "./assets/exit_1.xpm"
# define EXIT_2 "./assets/exit_2.xpm"
# define PLAYER_1 "./assets/player_1.xpm"
# define PLAYER_2 "./assets/player_2.xpm"
# define COLLECTIBLE_1 "./assets/collectible_1.xpm"
# define COLLECTIBLE_2 "./assets/collectible_2.xpm"
# define PX 64

# ifdef __linux__
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# elif __APPLE__
#  define KEY_ESC 53
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

void		fill_background(t_data *data, char *sprite);
char		get_element_by_position(t_data *data, int x, int y);
t_sprites	*init_sprites(t_data *data);
void		place_image(t_data *data, t_sprites *sprites, char element);
void		print_map(t_data *data, t_sprites *sprites, int frame);

void		sprites_frames(t_sprites *sprites, int frame);
int			frames(t_data *data);

void		get_position(t_data *data);
int			move_up(t_data *data);
int			move_down(t_data *data);
int			move_left(t_data *data);
int			move_right(t_data *data);

int			collectibles_left(char **map);
void		update_map(t_data *data);
int			keyboard_events(int key, void *data);

int			file_checker(const char *path, t_data *data);
t_data		*so_long_init(char *map_path);

char		*gnl_skip_whitespaces(int fd);
int			different_char(char *str);
int			check_map_components(char	**map);
int			check_map_chars(char	**map);
int			check_map(char **map);

char		**map_to_memory(const char *path);
char		**get_map(const char *path);

void		return_error(int error, t_data *data);
void		free_it(char **this);
void		leave(t_data *data);

#endif