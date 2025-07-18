/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:15:55 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/10 16:02:49 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_checker(const char *path, t_data *data, int to_close)
{
	int	file;

	file = open(path, O_RDONLY);
	if (file <= 0)
		return_error(2, data);
	else if (to_close)
	{
		close(file);
		return (1);
	}
	else
		return (file);
	return (0);
}

void	detect_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->x = x;
				data->y = y;
				data->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

t_data	*so_long_init(char *map_path)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return_error(135, data);
	null_init(data);
	data->map = get_map(data, map_path);
	detect_player(data);
	data->itoa_moves = (char *)ft_calloc(sizeof(char *), 1);
	if (!data->itoa_moves)
		return_error(136, data);
	data->collectibles = collectibles_left(data->map);
	data->mlx = mlx_init();
	if (!data->mlx)
		return_error(136, data);
	data->frame_1 = init_sprites(data);
	data->frame_2 = init_sprites(data);
	init_sprites_frames_1(data);
	init_sprites_frames_2(data);
	data->canva = init_canva(data);
	data->win = mlx_new_window(data->mlx, 13 * PX, 9 * PX, "so_long");
	if (!data->canva || !data->win)
		return_error(136, data);
	map_gameplay(data);
	return (data);
}

t_sprites	*init_sprites(t_data *data)
{
	t_sprites	*sprites;

	sprites = (t_sprites *)ft_calloc(1, sizeof(t_sprites));
	if (!sprites)
	{
		ft_printf("Error\nCan't initialize sprites.");
		return_error(134, data);
	}
	return (sprites);
}

t_canva	*init_canva(t_data *data)
{
	t_canva	*canva;

	canva = (t_canva *)ft_calloc(1, sizeof(t_canva));
	if (!canva)
	{
		ft_printf("Error\nCan't initialize canva.");
		return_error(134, data);
	}
	canva->img = mlx_new_image(data->mlx, 13 * PX, 9 * PX);
	if (!canva->img)
		return (NULL);
	return (canva);
}
