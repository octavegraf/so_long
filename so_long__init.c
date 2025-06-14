/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:15:55 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/14 14:32:53 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_checker(const char *path)
{
	int	file;

	file = open(path, O_RDONLY);
	if (file <= 0)
		return_error(2);
	else
		return (file);
	return (0);
}

t_sprites	*sprites_init(void)
{
	
}

t_data	*so_long_init(char *map_path)
{
	t_data	data;

	data.map = get_map(map_path);
	data.moves = 0;
	get_position(&data);
	data.collectibles = check_map_collectibles(data.map);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 608, "so_long");
	mlx_put_image_to_window()
}
