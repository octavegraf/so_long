/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__frames                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:08:35 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/16 17:53:44 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprites_frames(t_sprites *sprites, int frame)
{
	if (frame == 1)
	{
		sprites->background = BACKGROUND_1;
		sprites->collectible = COLLECTIBLE_1;
		sprites->empty = EMPTY_1;
		sprites->exit = EXIT_1;
		sprites->player = PLAYER_1;
		sprites->wall = WALL_1;
	}
	if (frame == 2)
	{
		sprites->background = BACKGROUND_2;
		sprites->collectible = COLLECTIBLE_2;
		sprites->empty = EMPTY_2;
		sprites->exit = EXIT_2;
		sprites->player = PLAYER_2;
		sprites->wall = WALL_2;
	}
}

int	frames(t_data *data)
{
	fill_background(data, BACKGROUND_1);
	print_map(data, data->sprites, 1);
	usleep(500000);
	fill_background(data, BACKGROUND_2);
	print_map(data, data->sprites, 2);
	return (0);
}