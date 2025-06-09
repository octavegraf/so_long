/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:28:26 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/09 14:11:22 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// typedef struct s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_data;

// typedef struct s_vars {
// 	void	*mlx;
// 	void	*win;
// 	t_data	img;
// 	int		color;
// }	t_vars;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	render_next_frame(void *param)
// {
// 	t_vars	*vars = (t_vars *)param;
// 	int		x, y;

// 	// Changer la couleur à chaque frame
// 	vars->color += 256; // Cela fait évoluer la couleur (composante verte)
// 	if (vars->color > 0xFFFFFF)
// 		vars->color = 0;

// 	// Dessine toute l’image avec cette couleur
// 	for (y = 0; y < 600; y++)
// 	{
// 		for (x = 0; x < 800; x++)
// 		{
// 			my_mlx_pixel_put(&vars->img, x, y, vars->color);
// 		}
// 	}

// 	// Affiche l’image
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 800, 600, "Test");
// 	vars.img.img = mlx_new_image(vars.mlx, 800, 600);
// 	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
// 									&vars.img.line_length, &vars.img.endian);
// 	vars.color = 0;

// 	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
// 	mlx_loop(vars.mlx);
// }
