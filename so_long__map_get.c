/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__map_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:31:28 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/09 17:12:08 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char	**map_to_memory(t_data *data, const char *path)
{
	char	**map;
	char	*line;
	char	*temp;
	int		file;

	file = file_checker(path, data, 0);
	map = NULL;
	line = get_next_line(file);
	while (line && *line)
	{
		temp = ft_strtrim(line, "\n");
		if (!temp)
			return (free_it(map), free(line), return_error(140, data), NULL);
		map = ft_array_add_row(map, temp);
		if (map)
			return (free(line), free(temp), free_it(map),
				return_error(140, data), NULL);
		free(line);
		free(temp);
		line = get_next_line(file);
	}
	if (line)
		free(line);
	close(file);
	return (map);
}

char	**get_map(t_data *data, const char *path)
{
	char	**map;

	map = map_to_memory(data, path);
	if (!map)
		return (ft_printf("%s", "Error: Can't create map\n"),
			return_error(133, data), NULL);
	if (check_map(map))
	{
		free_it(map);
		return (ft_printf("%s", "Error: Invalid map. A map must contain 1 exit,"
				" 1 starting position, at least 1 collectible and be surrounded"
				" by walls.\n"), return_error(134, data), NULL);
	}
	return (map);
}
