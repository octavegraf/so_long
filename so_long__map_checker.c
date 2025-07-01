/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__map_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:31:28 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/01 14:22:55 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*gnl_skip_whitespaces(int fd)
{
	char	*str;
	char	*temp;

	str = get_next_line(fd);
	temp = ft_strtrim(str, " \n\t\v\f\r");
	free(str);
	str = temp;
	while (str && !*str)
	{
		str = get_next_line(fd);
		temp = ft_strtrim(str, " \n\t\v\f\r");
		free(str);
		str = temp;
	}
	return (str);
}

int	different_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((i > 1) && (str[i] != str[i - 1]))
			return (1);
	}
	return (0);
}

int	check_map_components(char	**map, int i)
{
	int	j;
	int	c;
	int	e;
	int	p;

	i = -1;
	e = 0;
	p = 0;
	c = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				c++;
			else if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'P')
				p++;
		}
	}
	if (c < 1 || e != 1 || p != 1)
		return (1);
	return (0);
}

int	check_map_chars(char	**map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' &&
					map[i][j] != 'E' && map[i][j] != 'P')
				return (1);
		}
	}
	return (0);
}

int	check_map(char **map)
{
	int	i;
	int	length;
	int	error;

	i = 0;
	error = 0;
	length = ft_strlen(map[0]);
	error += different_char(map[0]);
	i = -1;
	while (map[++i])
	{
		if ((map[i][0] != '1') || (map[i][ft_strlen(map[i]) - 1] != '1')
		|| (int)ft_strlen(map[i]) != length)
			error++;
	}
	error += different_char(map[--i]);
	error += check_map_components(map, 0);
	error += check_map_chars(map);
	return (error);
}
