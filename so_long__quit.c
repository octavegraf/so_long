/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:20:48 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/10 16:03:25 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	return_error(int error, t_data *data)
{
	errno = error;
	if (error <= 132)
		perror("Error\n");
	if (error == 134)
		ft_printf("Error\nCan't initialize MLX.\n");
	if (error == 136)
		ft_printf("Error\nCan't initialize data.\n");
	if (data && data->itoa_moves)
		free(data->itoa_moves);
	if (data)
	{
		clear_everything(data);
		free(data);
	}
	exit(EXIT_FAILURE);
}

void	free_sprites(t_data *data, t_sprites *sprites)
{
	if (!sprites || !data || !data->mlx)
		return ;
	if (sprites->background)
		mlx_destroy_image(data->mlx, sprites->background);
	if (sprites->empty)
		mlx_destroy_image(data->mlx, sprites->empty);
	if (sprites->wall)
		mlx_destroy_image(data->mlx, sprites->wall);
	if (sprites->exit)
		mlx_destroy_image(data->mlx, sprites->exit);
	if (sprites->player)
		mlx_destroy_image(data->mlx, sprites->player);
	if (sprites->collectible)
		mlx_destroy_image(data->mlx, sprites->collectible);
}

void	free_it(char **this)
{
	int	i;

	i = -1;
	if (!this)
		return ;
	while (this && this[++i])
		free(this[i]);
	free(this);
}

void	leave(t_data *data)
{
	if (data->itoa_moves)
		free(data->itoa_moves);
	if (data)
	{
		clear_everything(data);
		free(data);
	}
	ft_printf("Thank you for playing the game. See you soon :)\n");
	exit(EXIT_SUCCESS);
}

void	clear_everything(t_data *data)
{
	get_next_line(-1);
	if (data && data->map)
		free_it(data->map);
	if (data && data->frame_1)
	{
		free_sprites(data, data->frame_1);
		free(data->frame_1);
	}
	if (data && data->frame_2)
	{
		free_sprites(data, data->frame_2);
		free(data->frame_2);
	}
	if (data && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data && data->canva)
	{
		mlx_destroy_image(data->mlx, data->canva->img);
		free(data->canva);
	}
	if (data && data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
