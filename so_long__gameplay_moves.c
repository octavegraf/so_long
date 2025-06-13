/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__gameplay_moves.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:06:34 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/13 16:29:18 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player_position	get_position(char **map)
{
	int					i;
	int					j;
	t_player_position	data;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				break ;
		}
		if (map[i][j] == 'P')
			break ;
	}
	data.y = i;
	data.x = j;
	return (data);
}

int	move_up(t_data *data)
{
	char				***map;
	t_player_position	player;

	map = &(data->map);
	player = get_position(*map);
	if (player.y >= 1 && (*map)[--player.y][player.x] != '1')
	{
			(*map)[player.y][player.x] = 'P';
			(*map)[++player.y][player.x] = '0';
	}
	else
		return (0);
	return (1);
}

int	move_down(t_data *data)
{
	char				***map;
	t_player_position	player;

	map = &(data->map);
	player = get_position(*map);
	if ((*map)[++player.y][0] && (*map)[player.y][player.x] != '1')
	{
			(*map)[player.y][player.x] = 'P';
			(*map)[--player.y][player.x] = '0';
	}
	else
		return (0);
	return (1);
}
