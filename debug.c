/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:06:24 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/22 17:01:34 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	*data;

	data = so_long_init("map_test");
	draw(data, data->frame_1, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->canva->img, 0, 0);
}
