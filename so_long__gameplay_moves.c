/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__gameplay_moves.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:06:34 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/13 20:19:38 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_position(t_data *data)
{
	int					i;
	int					j;
	char				***map;

	map = &data->map;
	i = -1;
	while ((*map)[++i])
	{
		j = -1;
		while ((*map)[i][++j])
		{
			if ((*map)[i][j] == 'P')
				break ;
		}
		if ((*map)[i][j] == 'P')
			break ;
	}
	(*map)[i][j] = '0';
	data->y = i;
	data->x = j;
	return (data);
}

int	move_up(t_data *data)
{
	char				***map;
	int					*x;
	int					*y;

	map = &data->map;
	*x = &data->x;
	*y = &data->y;
	if (*y >= 1 && (*map)[*y - 1][*x] != '1')
		*y--;
	else
		return (0);
	return (data->moves++, 1);
}

int	move_down(t_data *data)
{
	char				***map;
	int					*x;
	int					*y;

	map = &data->map;
	x = &data->x;
	y = &data->y;
	if ((*map)[*y + 1] && (*map)[*y + 1][*x] != '1')
		*y++;
	else
		return (0);
	return (data->moves++, 1);
}

int	move_left(t_data *data)
{
	char				***map;
	int					*x;
	int					*y;

	map = &data->map;
	*x = &data->x;
	*y = &data->y;
	if (x >= 1 && (*map)[*y][*x - 1] != '1')
		*x--;
	else
		return (0);
	return (data->moves++, 1);
}

int	move_right(t_data *data)
{
	char				***map;
	int					*x;
	int					*y;

	map = &data->map;
	*x = &data->x;
	*y = &data->y;
	if ((*map)[*y][*x + 1] && (*map)[*y][*x + 1] != '1')
		*x++;
	else
		return (0);
	return (data->moves++, 1);
}
