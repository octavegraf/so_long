/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__gameplay_moves.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:06:34 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/24 15:53:19 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_data *data)
{
	if (data->y > 0 && data->map[data->y - 1][data->x] != '\0'
			&& data->map[data->y - 1][data->x] != '1')
	{
		data->y -= 1;
		return (1);
	}
	return (0);
}

int	move_down(t_data *data)
{
	if (data->map[data->y + 1][data->x] != '\0'
			&& data->map[data->y + 1][data->x] != '1')
	{
		data->y += 1;
		return (1);
	}
	return (0);
}

int	move_left(t_data *data)
{
	if (data->x > 0 && data->map[data->y][data->x - 1] != '1')
	{
		data->x -= 1;
		return (1);
	}
	return (0);
}

int	move_right(t_data *data)
{
	if (data->map[data->y][data->x + 1] != '\0'
			&& data->map[data->y][data->x + 1] != '1')
	{
		data->x += 1;
		return (1);
	}
	return (0);
}
