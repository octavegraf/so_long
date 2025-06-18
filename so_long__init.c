/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:15:55 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/18 14:20:53 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_checker(const char *path, t_data *data)
{
	int	file;

	file = open(path, O_RDONLY);
	if (file <= 0)
		return_error(2, data);
	else
		return (file);
	return (0);
}

void	detect_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->x = x;
				data->y = y;
			}
			x++;
		}
		y++;
	}
}

t_data	*so_long_init(char *map_path)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_printf("Error : Can't initialize data.");
		return_error(134, data);
	}
	data->map = get_map(map_path);
	data->moves = 0;
	detect_player(data);
	data->collectibles = check_map_components(data->map);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 832, 576, "so_long");
	data->frame_1 = init_sprites(data);
	data->frame_2 = init_sprites(data);
	init_sprites_frames_1(data);
	init_sprites_frames_2(data);
	data->canva = init_canva(data);
	return (data);
}

t_sprites	*init_sprites(t_data *data)
{
	t_sprites	*sprites;

	sprites = malloc(sizeof(t_sprites));
	if (!sprites)
	{
		ft_printf("Error : Can't initialize sprites.");
		return_error(134, data);
	}
	return (sprites);
}

t_canva	*init_canva(t_data *data)
{
	t_canva	*canva;

	canva = malloc(sizeof(t_canva));
	if (!canva)
	{
		ft_printf("Error : Can't initialize canva.");
		return_error(134, data);
	}
	canva->img = mlx_new_image(data->mlx, 12 * PX, 8 * PX);
	canva->i_bpp = 0;
	canva->i_size_line = 0;
	canva->i_endian = 0;
	canva->sprite = NULL;
	canva->s_bpp = 0;
	canva->s_size_line = 0;
	canva->s_endian = 0;
	return (canva);
}
