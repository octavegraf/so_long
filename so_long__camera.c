/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:28:26 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/16 17:58:33 by ocgraf           ###   ########.fr       */
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
		if (x - 6 >= 0 && x - 6 <= ((int)ft_strlen(data->map[i])))
			result = data->map[y - 4][x - 6];
	}
	if (!result)
		result = '1';
	return (result);
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

void	place_image(t_data *data, t_sprites *sprites, char element)
{
	int		width;
	int		height;
	void	*sprite;

	if (element == '1')
		sprite = mlx_xpm_file_to_image(data->mlx, sprites->wall, &width,
				&height);
	else if (element == 'E')
		sprite = mlx_xpm_file_to_image(data->mlx, sprites->exit, &width,
				&height);
	else if (element == 'C')
		sprite = mlx_xpm_file_to_image(data->mlx, sprites->collectible, &width,
				&height);
	else
		sprite = mlx_xpm_file_to_image(data->mlx, sprites->empty, &width,
				&height);
	mlx_put_image_to_window(data->mlx, data->win, sprite, sprites->x * PX,
		sprites->y * PX);
}

void	print_map(t_data *data, t_sprites *sprites, int frame)
{
	int		width;
	int		height;
	void	*player;

	sprites_frames(sprites, frame);
	sprites->y = 0;
	while (sprites->y <= 12)
	{
		sprites->x = 0;
		while (sprites->x <= 8)
		{
			place_image(data, sprites, get_element_by_position(data, sprites->x,
					sprites->y));
			sprites->x += 1;
		}
		sprites->y += 1;
	}
	player = mlx_xpm_file_to_image(data->mlx, sprites->player, &width, &height);
	mlx_put_image_to_window(data->mlx, data->win, player, 6 * PX, 4 * PX);
	mlx_do_sync(data->mlx);
}
