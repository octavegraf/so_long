/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__gameplay.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:15:27 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/25 15:38:35 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectibles_left(char **map)
{
	int	i;
	int	j;
	int	collectibles;

	i = -1;
	collectibles = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'C')
				collectibles++;
	}
	return (collectibles);
}

void	update_map(t_data *data)
{
	if (data->map[data->y][data->x] == 'C')
	{
		data->collectibles -= 1;
		data->map[data->y][data->x] = '0';
	}
	else if (data->map[data->y][data->x] == 'E' && data->collectibles == 0)
		leave(data);
}

int	keyboard_events(int key, void *data)
{
	t_data	*gameplay;
	int		response;

	gameplay = (t_data *)data;
	response = 0;
	if (key == KEY_W || key == KEY_UP)
		response = move_up(gameplay);
	else if (key == KEY_S || key == KEY_DOWN)
		response = move_down(gameplay);
	else if (key == KEY_A || key == KEY_LEFT)
		response = move_left(gameplay);
	else if (key == KEY_D || key == KEY_RIGHT)
		response = move_right(gameplay);
	else if (key == KEY_ESC || key == 17)
		leave(data);
	if (response)
	{
		gameplay->moves += 1;
		update_map(gameplay);
	}
	return (0);
}

int	cross_button(void *void_data)
{
	t_data	*data;

	data = (t_data *)void_data;
	leave(data);
	return (0);
}
