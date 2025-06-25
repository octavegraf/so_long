/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__map_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:31:28 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/25 12:36:33 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_to_memory(t_data *data, const char *path)
{
	char	**map;
	char	*temp;
	char	*line;
	int		file;

	file = file_checker(path, data);
	map = NULL;
	temp = gnl_skip_whitespaces(file);
	while (temp && *temp)
	{
		line = ft_strtrim(temp, " \n\t\v\f\r");
		free(temp);
		if (line && *line)
			ft_tab_add_row(&map, line);
		free(line);
		temp = get_next_line(file);
	}
	if (temp)
		free(temp);
	return (map);
}

char	**get_map(t_data *data, const char *path)
{
	char	**map;

	map = map_to_memory(data, path);
	if (!map)
		return (ft_printf("%s", "Error: Can't create map"),
			return_error(133, NULL), NULL);
	if (check_map(map))
	{
		free_it(map);
		return (ft_printf("%s", "Error: Invalid map. A map must contain 1 exit,"
				" 1 starting position, at least 1 collectible and be surrounded"
				" by walls."), return_error(134, NULL), NULL);
	}
	return (map);
}
