/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__map_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:31:28 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/09 14:16:11 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(const char *path)
{
	char	**map;
	char	*temp;
	char	*line;
	int		file;

	ft_printf("%s", "Getting map");
	file = file_checker(path);
	map = NULL;
	while (1)
	{
		temp = get_next_line(file);
		if (temp)
		{
			line = ft_strtrim(temp, "\n");
			free(temp);
			ft_tab_add_row(map, line);
		}
		if (!temp)
			break ;
	}
	return (map);
}

int	different_char(char *str)
{
	int	i;

	ft_printf("%s", "Checking different chars");
	i = -1;
	while (str[++i])
	{
		if ((i > 1) && (str[i] != str[i - 1]))
			return (1);
	}
	return (0);
}

int	check_map_collectibles(char	**map)
{
	int	i;
	int	c;
	int	e;
	int	p;

	ft_printf("%s", "Checking collectibles");
	i = -1;
	e = 0;
	p = 0;
	c = 0;
	while (map[++i])
	{
		if (ft_strrchr(map[i], 'C'))
			c++;
		if (ft_strrchr(map[i], 'E'))
			e++;
		if (ft_strrchr(map[i], 'P'))
			p++;
	}
	if (c < 1 || e != 1 || p != 1)
		return (1);
	else
		return (0);
}

int	check_map(char **map)
{
	int	i;
	int	length;
	int	error;

	ft_printf("%s", "Checking map");
	i = 0;
	error = 0;
	length = ft_strlen(map[0]);
	error += different_char(map[0]);
	while (map[++i])
	{
		if ((map[i][0] != '1') || (map[i][ft_strlen(map[i])] != '1')
		|| ft_strlen(map[i]) != length)
		error++;
	}
	error += different_char(map[--i]);
	error += check_map_collectibles(map);
	if (error)
		ft_printf("%s", "Invalid map");
	else
		ft_printf("%s", "The map is valid.");
}
