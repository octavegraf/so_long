/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__visuals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:28:26 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/15 15:55:49 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_background(t_data *data, char *sprite)
{
	void	*background;
	int		width;
	int		height;
	int		y;
	int		x;

	if (!file_checker(sprite, data))
		return ;
	file_checker(sprite, data);
	background = mlx_xpm_file_to_image(data->mlx, sprite, &width, &height);
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
	mlx_do_sync(data->mlx);
}

char	get_element_by_position(t_data *data, int x, int y)
{
	int		i;
	char	result;

	i = 0;
	result = 0;
	while (data->map[i])
		i++;
	if (y - 4 >= 0 && y - 4 <= i)
	{
		if (x - 6 >= 0 && x - 6 <= (int)ft_strlen(data->map[i]))
			result = data->map[y - 4][x - 6];
	}
	if (!result)
		result = '1';
	return (result);
}

int	frame_1(t_data *data)
{
	fill_background(data, BACKGROUND_1);
	usleep(500000);
	fill_background(data, BACKGROUND_2);
	usleep(500000);
	return (0);
}
