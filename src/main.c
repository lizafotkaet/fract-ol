/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 01:04:20 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/07/29 12:07:40 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	fract_data_init(t_data *fractal)
{
	fractal->palette = get_palettes();
	fractal->palette_index = 0;
	fractal->palette = &fractal->palette[0];
	fractal->palette_len = pallete_len(fractal);
	fractal->smooth = false;
	fractal->limit->x = -2;
	fractal->limit->y = 2;
	fractal->max_iter = 35;
	fractal->center->x = -0.5;
	fractal->center->y = 0;
	fractal->zoom_factor = 3.5;
	if (fractal->type == 2)
		zero(fractal->center);
}

void	init_image(t_data *fractal)
{
	fractal->mlx = mlx_init(SIZE, SIZE, fract_name(fractal->type), false);
	if (!fractal->mlx)
	{
		error_exit(fractal, MLX_ERR);
	}
	fractal->img = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (!fractal->img)
	{
		error_exit(fractal, IMG_ERR);
	}
	draw_fractal(fractal);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	mlx_loop_hook(fractal->mlx, &get_hook, fractal);
	mlx_loop(fractal->mlx);
}

void	check_input(int argc, char **argv, t_data *fractal, int *error)
{
	if (argc == 2 && ft_atoi(argv[1], error) == 1)
	{
		fractal->type = 1;
	}
	else if (argc == 2 && ft_atoi(argv[1], error) == 2)
	{
		fractal->type = 2;
		fractal->constant->x = C_REAL;
		fractal->constant->y = C_IMAG;
	}
	else if (argc == 4 && ft_atoi(argv[1], error) == 2)
	{
		fractal->type = 2;
		fractal->constant->x = ft_atof(argv[2]);
		fractal->constant->y = ft_atof(argv[3]);
	}
	else
	{
		use_msg(fractal);
	}
}

int	main(int argc, char **argv)
{
	t_data		*fractal;
	int			error;

	error = 0;
	fractal = NULL;
	ft_printf("Starting...\n");
	ft_malloc(&fractal);
	ft_printf("Memory allocated\n");
	check_input(argc, argv, fractal, &error);
	ft_printf("Input checked: type=%d\n", fractal->type);
	fract_data_init(fractal);
	ft_printf("Fractal data initialized\n");
	init_image(fractal);
	ft_printf("Image initialized\n");
	return (0);
}
