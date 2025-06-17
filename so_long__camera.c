/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:28:26 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/17 18:13:36 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_background(t_data *data, void *background)
{
	int	y;
	int	x;

	y = 0;
	while (y <= PX * 8)
	{
		x = 0;
		while (x <= PX * 12)
		{
			mlx_put_image_to_window(data->mlx, data->win, background, x, y);
			x += PX;
		}
		y += PX;
	}
}

char	get_element_by_position(t_data *data, int x, int y)
{
	int		i;
	char	result;

	x += data->x - 6;
	y += data->y - 4;
	i = 0;
	result = 0;
	while (data->map[i])
		i++;
	i--;
	if (y >= 0 && y <= i)
	{
		if (x >= 0 && data->map[i] && x <= ((int)ft_strlen(data->map[i])))
			result = data->map[y][x];
	}
	if (!result)
		result = '1';
	return (result);
}



void	print_map(t_data *data, t_sprites *sprites, int x, int y)
{
	y = -1;
	while (++y < 12)
	{
		x = -1;
		while (++x < 8)
		{
			if (get_element_by_position(data, x, y) == '0')
				mlx_put_image_to_window(data->mlx, data->win, sprites->empty,
					x * PX, y * PX);
			else if (get_element_by_position(data, x, y) == '1')
				mlx_put_image_to_window(data->mlx, data->win, sprites->wall,
					x * PX, y * PX);
			else if (get_element_by_position(data, x, y) == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					sprites->collectible, x * PX, y * PX);
			else if (get_element_by_position(data, x, y) == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					sprites->exit, x * PX, y * PX);
			else if (get_element_by_position(data, x, y) == 'P')
				mlx_put_image_to_window(data->mlx, data->win, sprites->player,
					x * PX, y * PX);
		}
	}
}
