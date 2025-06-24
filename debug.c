/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:06:24 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/24 11:58:06 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	*data;

	data = so_long_init("map_test");
	mlx_key_hook(data->win, keyboard_events, data);
	mlx_loop_hook(data->mlx, frames, data);
	mlx_loop(data->mlx);
}
