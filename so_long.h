/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:25:58 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/10 15:48:02 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include <errno.h>
# include <string.h>

char	*gnl_skip_whitespaces(int fd);
int		check_map(char **map);
int		check_map_collectibles(char	**map);
int		different_char(char *str);
int		file_checker(const char *path);
char	**get_map(const char *path);
int		check_map(char **map);
char	**map_to_memory(const char *path);
void	return_error(int error);

#endif