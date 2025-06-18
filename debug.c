/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:06:24 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/18 16:58:00 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	*data;

	data = so_long_init("map_test");
	draw(data, data->frame_1, 0, 0);
	data->img1 = data->canva->img;
	mlx_put_image_to_window(data->mlx, data->win, data->img1, 0, 0);
	return (0);
}
