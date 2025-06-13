/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:06:24 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/13 16:35:40 by ocgraf           ###   ########.fr       */
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

int	gameplay_key(int key, void *data)
{
	t_data	*gameplay;

	gameplay = (t_data *)data;
	if (key == KEY_W || key == KEY_UP)
		move_up(gameplay);
	if (key == KEY_S || key == KEY_DOWN)
		move_down(gameplay);
	printf_tab(gameplay->map);
	ft_printf("\n");
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	gameplay;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "so_long");
	gameplay.map = get_map("map_test");
	gameplay.count = 0;
	mlx_key_hook(win, gameplay_key, &gameplay);
	mlx_loop(mlx);
}
