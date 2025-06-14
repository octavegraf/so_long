/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:25:58 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/14 14:32:30 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include <errno.h>
# include <string.h>

typedef struct s_data
{
	char	**map;
	int		x;
	int		y;
	int		moves;
	int		collectibles;
	void	*mlx;
	void	*win;
}	t_data;

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

void	get_position(t_data *data);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
int		collectibles_left(char **map);
void	update_map(t_data *data);
int		keyboard_events(int key, void *data, void *mlx, void *win);
int		file_checker(const char *path);
t_data	*so_long_init(char *map_path);
char	*gnl_skip_whitespaces(int fd);
int		different_char(char *str);
int		check_map_components(char **map);
int		check_map_chars(char	**map);
int		check_map(char **map);
char	**map_to_memory(const char *path);
char	**get_map(const char *path);
void	return_error(int error);
void	free_it(char **this);
void	leave(t_data *data);

#endif