/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:15:55 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/14 19:14:38 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_checker(const char *path, t_data *data)
{
	int	file;

	file = open(path, O_RDONLY);
	if (file <= 0)
		return_error(2, data);
	else
		return (file);
	return (0);
}

t_data	*so_long_init(char *map_path)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_printf("Error : Can't initialize data.");
		return_error(134, data);
	}
	data->map = get_map(map_path);
	data->moves = 0;
	get_position(data);
	data->collectibles = check_map_components(data->map);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 832, 576, "so_long");
	return (data);
}
