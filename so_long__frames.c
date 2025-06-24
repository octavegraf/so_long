/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__frames.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:08:35 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/24 15:53:12 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/time.h>

void	init_sprites_frames_1(t_data *data)
{
	int	width;
	int	height;

	if ((!file_checker(BACKGROUND_1, data))
		|| (!file_checker(COLLECTIBLE_1, data))
		|| (!file_checker(EMPTY_1, data))
		|| (!file_checker(EXIT_1, data))
		|| (!file_checker(PLAYER_1, data))
		|| (!file_checker(WALL_1, data)))
		return ;
	data->frame_1->background = mlx_xpm_file_to_image(data->mlx,
			BACKGROUND_1, &width, &height);
	data->frame_1->collectible = mlx_xpm_file_to_image(data->mlx,
			COLLECTIBLE_1, &width, &height);
	data->frame_1->empty = mlx_xpm_file_to_image(data->mlx,
			EMPTY_1, &width, &height);
	data->frame_1->exit = mlx_xpm_file_to_image(data->mlx,
			EXIT_1, &width, &height);
	data->frame_1->player = mlx_xpm_file_to_image(data->mlx,
			PLAYER_1, &width, &height);
	data->frame_1->wall = mlx_xpm_file_to_image(data->mlx,
			WALL_1, &width, &height);
}

void	init_sprites_frames_2(t_data *data)
{
	int	width;
	int	height;

	if ((!file_checker(BACKGROUND_2, data))
		|| (!file_checker(COLLECTIBLE_2, data))
		|| (!file_checker(EMPTY_2, data))
		|| (!file_checker(EXIT_2, data))
		|| (!file_checker(PLAYER_2, data))
		|| (!file_checker(WALL_2, data)))
		return ;
	data->frame_2->background = mlx_xpm_file_to_image(data->mlx,
			BACKGROUND_2, &width, &height);
	data->frame_2->collectible = mlx_xpm_file_to_image(data->mlx,
			COLLECTIBLE_2, &width, &height);
	data->frame_2->empty = mlx_xpm_file_to_image(data->mlx,
			EMPTY_2, &width, &height);
	data->frame_2->exit = mlx_xpm_file_to_image(data->mlx,
			EXIT_2, &width, &height);
	data->frame_2->player = mlx_xpm_file_to_image(data->mlx,
			PLAYER_2, &width, &height);
	data->frame_2->wall = mlx_xpm_file_to_image(data->mlx,
			WALL_2, &width, &height);
}

int	frames(t_data *data)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (current_time.tv_usec < 500000)
	{
		draw(data, data->frame_1, 0, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->canva->img, 0, 0);
		mlx_string_put(data->mlx, data->win, 10, 18, 0, ft_itoa(data->moves));
	}
	else
	{
		draw(data, data->frame_2, 0, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->canva->img, 0, 0);
		mlx_string_put(data->mlx, data->win, 10, 18, 0, ft_itoa(data->moves));
	}
	return (0);
}
