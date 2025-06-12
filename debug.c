/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:06:24 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/12 14:58:02 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		x;
	int		y;

	x = 32;
	y = 32;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "so_long");
	img = mlx_xpm_file_to_image(mlx, "./test.xpm", &x, &y);
	void *img2 = mlx_xpm_file_to_image(mlx, "./test2.xpm", &x, &y);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img2, 50, 50);
	mlx_loop(mlx);
}
