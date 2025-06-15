/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:20:48 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/14 15:53:40 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	return_error(int error, t_data *data)
{
	errno = error;
	if (error <= 132)
		perror("Error");
	if (data->map)
		free_it(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_FAILURE);
}

void	free_it(char **this)
{
	int	i;

	i = -1;
	while (this[++i])
		free(this[i]);
	free(this);
}

void	leave(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_it(data->map);
	ft_printf("Thank you for playing the game. See you soon :)\n");
	exit(EXIT_SUCCESS);
}
