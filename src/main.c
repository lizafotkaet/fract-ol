/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:08:10 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/20 21:05:22 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	putpixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
{
	uint32_t	*pixels;

	pixels = (uint32_t *)img->pixels;
	pixels[y * img->width + x] = color;
}

int	main(void)
{
	mlx_t	*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(800, 600, "fractol", false);
	img = mlx_new_image(mlx, 800, 600);
	make_square(img, 5, 5, 50, 0xFF0000FF);
	mlx_image_to_window(mlx, img, 5, 5);
	mlx_loop(mlx);
	return (0);
}

