/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:36:33 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/24 23:29:30 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

unsigned int	mandelbrot_iterations(double x, double y, unsigned int max_iter) //maybe delete later
{
    t_complex	z_n;
    t_complex	c;
    unsigned int iter;

    c.x = x;
    c.y = y;
    z_n = zero();
    iter = 0;
    while (iter < max_iter)
    {
        z_n = add_complex(multiply_complex(z_n, z_n), c);
        if (abs_complex(z_n) > 2)
            return (iter);
        iter++;
    }
    return (max_iter);
}

uint32_t get_color(unsigned int iter, unsigned int max_iter) // maybe delete later
{
    double t;
    uint8_t r, g, b;
    
    if (iter == max_iter)
        return (0x000000FF); // Black for points in the set
    
    t = (double)iter / (max_iter / 8); // Normalize and scale
    
    // Create a smooth color gradient
    r = (uint8_t)(9 * (1 - t) * t * t * t * 255);
    g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
    b = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    
    return ((uint32_t)r << 24 | (uint32_t)g << 16 | (uint32_t)b << 8 | 0xFF);
}

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
	unsigned int	max_iter = 150; // maybe delete later
	unsigned int	iter; // maybe delete later

	width = data->mlx->width;
	height = data->mlx->height;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			real = data->min_real + (double)x * (data->max_real - data->min_real) / width;
            imag = data->min_imag + (double)y * (data->max_imag - data->min_imag) / height;
            iter = mandelbrot_iterations(real, imag, max_iter);
            mlx_put_pixel(data->img, x, y, get_color(iter, max_iter));
            x++;
		}
		y++;
		// if (y % 20 == 0)
		// 	mlx_loop_hook(data->mlx, NULL, NULL);
	}
}

// Transform pixel coordinates to complex plane coordinates
			// real = data->min_real + (double)x * (data->max_real - data->min_real) / width;
			// imag = data->min_imag + (double)y * (data->max_imag - data->min_imag) / height;
			// if (is_mandelbrot(real, imag, 150))
			// mlx_put_pixel(data->img, x, y, 0xFF0000FF);
			// else
			// mlx_put_pixel(data->img, x, y, 0x000000FF); // Black for points outside
			// x++;