/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:08:10 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/24 23:14:08 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	error_check(mlx_t **mlx, mlx_image_t **img)
{
	if (!(*mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true)))
	{
		ft_printf("%s\n", mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(*img = mlx_new_image(*mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(*mlx);
		ft_printf("%s\n", mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(*mlx, *img, 0, 0) == -1)
	{
		mlx_close_window(*mlx);
		ft_printf("%s\n", mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(void)
{
	mlx_t		*mlx = NULL;
	mlx_image_t	*img = NULL;
	t_data		data;
	
	if (error_check(&mlx, &img))
		return (EXIT_FAILURE);
	data.mlx = mlx;
	data.img = img;
	data.min_real = -2.5;
	data.max_real = 1.0;
	data.min_imag = -1.25;
	data.max_imag = 1.25;
	data.zoom_factor = 1.0;
	put_mandelbrot_fractal(&data);
	mlx_loop_hook(mlx, ft_hook, &data);
	mlx_scroll_hook(mlx, scroll_hook, &data);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
// double min_real = -2.5;
// double max_real = 1.0;
// double min_imag = -1.25;
// double max_imag = 1.25;