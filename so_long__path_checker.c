/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__path_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:38:54 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/25 17:29:11 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	**map_copy(char **map)
// {
// 	char	**copy;
// 	int		i;

// 	if (!map)
// 		return (NULL);
// 	copy = malloc(sizeof(char *) * (ft_tablen(map) + 1));
// 	if (!copy)
// 		return (NULL);
// 	i = -1;
// 	while (map[++i])
// 	{
// 		copy[i] = ft_strdup(map[i]);
// 		if (!copy[i])
// 		{
// 			free_it(copy);
// 			return (NULL);
// 		}
// 	}
// 	copy[i] = NULL;
// 	return (copy);
// }

// void	map_filler(char **map, int x, int y)
// {
// 	if (map[y][x] == '1' || map[y][x] == 'A')
// 		return ;
// 	map[y][x] = 'A';
// 	map_filler(map, x + 1, y);
// 	map_filler(map, x - 1, y);
// 	map_filler(map, x, y + 1);
// 	map_filler(map, x, y - 1);
// }

// int	map_path_checker(char **map)
// {
// 	int		x;
// 	int		y;

// 	y = -1;
// 	while (map && map[++y])
// 	{
// 		x = -1;
// 		while (map[y][++x])
// 		{
// 			if (map[y][x] == 'C' || map[y][x] == 'E')
// 				return (1);
// 		}
// 	}
// 	return (0);
// }

// void	map_gameplay(t_data *data)
// {
// 	char	**map_cpy;

// 	map_cpy = map_copy(data->map);
// 	if (!map_cpy)
// 		return_error(134, data);
// 	map_filler(map_cpy, data->x, data->y);
// 	if (map_path_checker(map_cpy))
// 	{
// 		ft_printf("%s", "Error: No path to exit or collectibles.\n");
// 		free_it(map_cpy);
// 		return_error(134, data);
// 	}
// }
