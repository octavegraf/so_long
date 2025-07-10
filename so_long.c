/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:04:57 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/10 16:04:00 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	null_init(t_data *data)
{
	data->map = NULL;
	data->x = 0;
	data->y = 0;
	data->moves = 0;
	data->itoa_moves = NULL;
	data->collectibles = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->frame_1 = NULL;
	data->frame_2 = NULL;
	data->canva = NULL;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc == 2 && (!ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4),
				".ber", 4)))
	{
		data = so_long_init(argv[1]);
		mlx_hook(data->win, 17, 0, cross_button, data);
		mlx_key_hook(data->win, keyboard_events, data);
		mlx_loop_hook(data->mlx, frames, data);
		mlx_loop(data->mlx);
	}
	else
		ft_printf("Error\nYou need to give the map path in .ber in argument."
			" Only 1 can be received.");
	return (0);
}
