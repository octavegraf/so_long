/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:25:58 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/26 16:43:37 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include <errno.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_sprites
{
	void	*background;
	void	*empty;
	void	*wall;
	void	*exit;
	void	*player;
	void	*collectible;
}	t_sprites;

typedef struct s_canva
{
	void	*img;
	int		i_bpp;
	int		i_size_line;
	int		i_endian;
	char	*i_px;
	void	*sprite;
	int		s_bpp;
	int		s_size_line;
	int		s_endian;
	char	*s_px;
}	t_canva;

typedef struct s_data
{
	char		**map;
	int			fd[16];
	int			x;
	int			y;
	int			moves;
	char		*itoa_moves;
	int			collectibles;
	void		*mlx;
	void		*win;
	t_sprites	*frame_1;
	t_sprites	*frame_2;
	t_canva		*canva;
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

void		fill_background(t_data *data, void *background);
char		get_element_by_position(t_data *data, int x, int y);
t_sprites	*init_sprites(t_data *data);
void		place_image(t_data *data, int x, int y, int bytes);
void		draw(t_data *data, t_sprites *sprites, int x, int y);
void		get_sprite_addr(t_data *data, t_sprites *sprites, char c);
void		get_canva_addr(t_data *data);

void		print_map(t_data *data, t_sprites *sprites, int x, int y);

void		sprites_frames(t_sprites *sprites, int frame);
void		init_sprites_frames_1(t_data *data);
void		init_sprites_frames_2(t_data *data);
t_canva		*init_canva(t_data *data);
int			frames(t_data *data);

int			move_up(t_data *data);
int			move_down(t_data *data);
int			move_left(t_data *data);
int			move_right(t_data *data);

int			collectibles_left(char **map);
void		update_map(t_data *data);
int			keyboard_events(int key, void *data);
int			cross_button(void *void_data);

int			file_checker(const char *path, t_data *data, int to_close);
void		detect_player(t_data *data);
t_data		*so_long_init(char *map_path);

char		*gnl_skip_whitespaces(int fd);
int			different_char(char *str);
int			check_map_components(char	**map);
int			check_map_chars(char	**map);
int			check_map(char **map);

char		**map_to_memory(t_data *data, const char *path);
char		**get_map(t_data *data, const char *path);

char		**map_copy(char **map);
void		map_filler(char **map, int x, int y);
int			map_path_checker(char **map);
void		map_gameplay(t_data *data);


void		return_error(int error, t_data *data);
void		free_sprites(t_data *data, t_sprites *sprites);
void		free_it(char **this);
void		leave(t_data *data);
void		clear_everything(t_data *data);

#endif