/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:08:10 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/24 22:07:55 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	put_fractal(mlx_t	*mlx, mlx_image_t *img)
{
	double	width;
	double height;

	double min_real = -2.5;
    double max_real = 1.0;
    double min_imag = -1.25;
    double max_imag = 1.25;

	width = mlx->width;
	height = mlx->height;

	for (int32_t y = 0; y < height; y++)
    {
        for (int32_t x = 0; x < width; x++)
        {
            // Transform pixel coordinates to complex plane coordinates
            double real = min_real + (double)x * (max_real - min_real) / width;
            double imag = min_imag + (double)y * (max_imag - min_imag) / height;
            
            if (is_mandelbrot(real, imag, 1000))
                mlx_put_pixel(img, x, y, 0xFF0000FF);
            else
                mlx_put_pixel(img, x, y, 0x000000FF); // Black for points outside
        }
    }
}

int	error_check(mlx_t **mlx, mlx_image_t **img)
{
	if (!(*mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true)))
	{
		ft_printf("%s\n", mlx_strerror(mlx_errno)); //puts() is from <stdio.h>!!! replace later!!
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
	put_fractal(mlx, img);
	mlx_loop_hook(mlx, ft_hook, &data);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}

// static mlx_image_t* image;

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel
// 			(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }



// int32_t main(void)
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
