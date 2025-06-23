/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:06:24 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/23 15:20:58 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill_canva(t_data *data, unsigned int color)
{
	int bpp, sl, endian;
	int width, height;

	void *test = mlx_xpm_file_to_image(data->mlx, BACKGROUND_1, &width, &height);
	char *testaddr = mlx_get_data_addr(test, &bpp, &sl, &endian);
	void *img = mlx_new_image(data->mlx, width, height);
	char *imgaddr = mlx_get_data_addr(img, &bpp, &sl, &endian);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < sl; x++)
		{
			imgaddr[y * sl + x] = testaddr[y * sl + x];
			mlx_put_image_to_window(data->mlx, data->win, img, 0, 0);

		}
	}
	(void)color;
}



int	main(void)
{
	t_data	*data;

	data = so_long_init("map_test");
	draw(data, data->frame_1, 0, 0);
	fill_canva(data, 0x00FF00);
	//mlx_put_image_to_window(data->mlx, data->win, data->canva->img, 0, 0);
	mlx_loop(data->mlx);
}
