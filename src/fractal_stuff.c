/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:36:33 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/24 22:39:55 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

bool	is_mandelbrot(double x, double y, unsigned int n) // n - how many times we check if it fits (|z| <= 2)
{
	t_complex	z_n;
	t_complex	c; // the coordinate of the pixel

	c.x = x;
	c.y = y;
	z_n = zero();
	while (n-- > 0)
	{
		z_n = add_complex(multiply_complex(z_n, z_n), c);
		if (abs_complex(z_n) > 2)
			return (false);
	}
	return (true);
}

void	put_mandelbrot_fractal(t_data *data)
{
	double		width;
	double 		height;
	double		real; // complex plane coordinates
	double		imag;
	uint32_t	x;
	uint32_t	y;

	width = data->mlx->width;
	height = data->mlx->height;
	y = 0;
	while (y++ < height)
	{
		while (x++ < width)
		{
			// Transform pixel coordinates to complex plane coordinates
			real = data->min_real + (double)x * (data->max_real - data->min_real) / width;
			imag = data->min_imag + (double)y * (data->max_imag - data->min_imag) / height;
			if (is_mandelbrot(real, imag, 1000))
			mlx_put_pixel(data->img, x, y, 0xFF0000FF);
			else
			mlx_put_pixel(data->img, x, y, 0x000000FF); // Black for points outside
		}
	}
}
// double min_real = -2.5;
// double max_real = 1.0;
// double min_imag = -1.25;
// double max_imag = 1.25;



