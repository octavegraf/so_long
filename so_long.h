/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:25:58 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/13 16:32:10 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include <errno.h>
# include <string.h>

typedef struct s_data{
	int		count;
	char	**map;
}	t_data;

typedef struct s_player_position {
	int	x;
	int	y;
}	t_player_position;

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
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# endif

char				*gnl_skip_whitespaces(int fd);
int					check_map(char **map);
int					check_map_collectibles(char	**map);
int					different_char(char *str);
int					file_checker(const char *path);
char				**get_map(const char *path);
int					check_map(char **map);
char				**map_to_memory(const char *path);
void				return_error(int error);
t_player_position	get_position(char **map);
int					move_up(t_data *data);
int					move_down(t_data *data);

#endif