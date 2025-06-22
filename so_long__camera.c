/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:28:26 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/22 17:51:44 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_data *data, t_sprites *sprites, int x, int y)
{
	y = -1;
	while (++y <= 8)
	{
		x = -1;
		while (++x <= 12)
		{
			get_sprite_addr(data, sprites, '\0');
			place_image(data, data->canva, x, y);
		}
	}
	y = -1;
	while (++y <= 8)
	{
		x = -1;
		while (++x <= 12)
		{
			get_sprite_addr(data, sprites, get_element_by_position(data, x, y));
			place_image(data, data->canva, x * PX, y * PX);
		}
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
		if (x >= 0 && data->map[y] && x < (int)ft_strlen(data->map[y]))
			result = data->map[y][x];
	}
	return (result);
}

void	get_sprite_addr(t_data *data, t_sprites *sprites, char c)
{
	int		*s_bpp;
	int		*s_size_line;
	int		*s_endian;

	s_bpp = &data->canva->s_bpp;
	s_size_line = &data->canva->s_size_line;
	s_endian = &data->canva->s_endian;
	if (c == '0')
		mlx_get_data_addr(sprites->empty, s_bpp, s_size_line, s_endian);
	else if (c == '1')
		mlx_get_data_addr(sprites->wall, s_bpp, s_size_line, s_endian);
	else if (c == 'C')
		mlx_get_data_addr(sprites->collectible, s_bpp, s_size_line, s_endian);
	else if (c == 'E')
		mlx_get_data_addr(sprites->exit, s_bpp, s_size_line, s_endian);
	else if (c == 'P')
		mlx_get_data_addr(sprites->player, s_bpp, s_size_line, s_endian);
	else if (!c)
		mlx_get_data_addr(sprites->background, s_bpp, s_size_line, s_endian);
}

void	place_image(t_data *data, t_canva *canva, int x, int y)
{
	int				i;
	int				j;
	int				src;
	int				dst;
	unsigned int	color;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			src = (i * canva->i_size_line) + (j * (canva->i_bpp / 8));
			dst = ((y * 64 + i) * canva->i_size_line) + ((x * 64 + j)
					* (canva->i_bpp / 8));
			color = *(unsigned int *)(canva->img + src);
			*(unsigned int *)(canva->img + dst) = color;
			j++;
		}
		i++;
	}
	(void)data;
}
