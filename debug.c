/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:06:24 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/17 17:32:50 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printf_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		ft_printf("%s\n", tab[i]);
}

int	main(void)
{
	t_data	*data;

	data = so_long_init("map_test");
	init_sprites_frames_1(data);
	init_sprites_frames_2(data);
	mlx_key_hook(data->win, keyboard_events, data);
	mlx_loop_hook(data->mlx, frames, data);
	mlx_loop(data->mlx);
	return (0);
}
