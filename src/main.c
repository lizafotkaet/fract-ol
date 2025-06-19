/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:08:10 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/18 16:12:07 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

// int	clean_up_img(t_data *img, t_vars *vars)
// {
// 	if (img->img)
// 		mlx_destroy_image(vars->mlx, img->img);
// 	if (img->win)
// 		mlx_destroy_window(vars->mlx, img->win);
// 	free(img);
// 	return (0);
// }

int close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	
	vars.mlx = NULL;
	vars.mlx = mlx_init();
	vars.win = NULL;
	if (!vars.mlx)
	{
		ft_putstr_fd("Error: mlx_init failed\n", 2);
		return (1);
	}
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Fract-ol");
	if (!vars.win)
	{
		ft_putstr_fd("Error: mlx_new_window failed\n", 2);
		free(vars.mlx);
		return (1);
	}
	mlx_hook(vars.win, ON_DESTROY, 0, close_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 800, 600, "Fract-ol");
// 	img.img = mlx_new_image(mlx, 800, 600);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
// 			&img.line_length, &img.endian);
// 	make_circle(&img, 100, 100, 50, 0x00FF0000); // Red circle
// 	make_circle(&img, 200, 200, 80, 0xFFFF00FF); // Magenta circle
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 5, 5);
// 	mlx_hook(mlx_win, ON_DESTROY, 0, close_win, &mlx_win);
// 	mlx_loop(mlx);
// 	return (0);
// }
