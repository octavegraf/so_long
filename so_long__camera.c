/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:28:26 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/27 12:25:15 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_data *data, t_sprites *sprites, int x, int y)
{
	get_canva_addr(data);
	y = -1;
	while (++y <= 8)
	{
		x = -1;
		while (++x <= 12)
		{
			get_sprite_addr(data, sprites, '\0');
			place_image(data, x, y, 0);
		}
	}
	y = -1;
	while (++y <= 8)
	{
		x = -1;
		while (++x <= 12)
		{
			get_sprite_addr(data, sprites, get_element_by_position(data, x, y));
			place_image(data, x, y, 0);
		}
	}
	get_sprite_addr(data, sprites, 'P');
	place_image(data, 6, 4, 0);
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
		data->canva->s_px = mlx_get_data_addr(sprites->empty, s_bpp,
				s_size_line, s_endian);
	else if (c == '1')
		data->canva->s_px = (mlx_get_data_addr(sprites->wall, s_bpp,
					s_size_line, s_endian));
	else if (c == 'C')
		data->canva->s_px = (mlx_get_data_addr(sprites->collectible, s_bpp,
					s_size_line, s_endian));
	else if (c == 'E')
		data->canva->s_px = (mlx_get_data_addr(sprites->exit, s_bpp,
					s_size_line, s_endian));
	else if (c == 'P')
		data->canva->s_px = (mlx_get_data_addr(sprites->player, s_bpp,
					s_size_line, s_endian));
	else if (!c)
		data->canva->s_px = (mlx_get_data_addr(sprites->background, s_bpp,
					s_size_line, s_endian));
}

void	get_canva_addr(t_data *data)
{
	int		*i_bpp;
	int		*i_size_line;
	int		*i_endian;

	i_bpp = &data->canva->i_bpp;
	i_size_line = &data->canva->i_size_line;
	i_endian = &data->canva->i_endian;
	data->canva->i_px = mlx_get_data_addr(data->canva->img, i_bpp,
			i_size_line, i_endian);
}

void	place_image(t_data *data, int x, int y, int b)
{
	int		i;
	int		j;
	int		src_px;
	int		dst_px;
	int		bpp;

	x *= PX;
	y *= PX;
	bpp = data->canva->s_bpp / 8;
	j = -1;
	while (++j < PX)
	{
		i = -1;
		while (++i < PX)
		{
			src_px = j * data->canva->s_size_line + i * bpp;
			dst_px = (y + j) * data->canva->i_size_line + (x + i) * bpp;
			if (data->canva->s_px[src_px] == 0)
				continue ;
			b = -1;
			while (++b < bpp)
				data->canva->i_px[dst_px + b] = data->canva->s_px[src_px + b];
		}
	}
}
