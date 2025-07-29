/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:51:45 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/07/29 11:44:31 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	draw_fractal(t_data *fractal)
{
	fractal->pixel->y = 0;
	while (fractal->pixel->y < SIZE)
	{
		fractal->pixel->x = 0;
		while (fractal->pixel->x < SIZE)
		{
			if (fractal->type == 1)
				mandelbrot(fractal);
			else if (fractal->type == 2)
				julia(fractal);
			(fractal->pixel->x)++;
		}
		(fractal->pixel->y)++;
	}
}

void	mandelbrot(t_data *fractal)
{
	t_complex	z_curr;
	double		curr_abs;

	fractal->constant->x = (fractal->pixel->x - SIZE
			/ 2.0f) * fractal->zoom_factor / SIZE + fractal->center->x;
	fractal->constant->y = (fractal->pixel->y - SIZE
			/ 2.0f) * fractal->zoom_factor / SIZE + fractal->center->y;
	fractal->iter = 0;
	z_curr.x = 0;
	z_curr.y = 0;
	curr_abs = abs_complex(z_curr);
	while (fractal->iter <= fractal->max_iter)
	{
		if (curr_abs > 2)
			break ;
		z_curr = add_complex(sqr_complex(z_curr), fractal->constant);
		curr_abs = abs_complex(z_curr);
		fractal->iter++;
	}
	fractal->z->x = z_curr.x;
	fractal->z->y = z_curr.y;
	put_pixel(fractal);
}

void	julia(t_data *fractal)
{
	t_complex	z_curr;
	double		curr_abs;

	z_curr.x = (fractal->pixel->x - SIZE
			/ 2.0f) * fractal->zoom_factor / SIZE + fractal->center->x;
	z_curr.y = (fractal->pixel->y - SIZE
			/ 2.0f) * fractal->zoom_factor / SIZE + fractal->center->y;
	fractal->iter = 0;
	curr_abs = abs_complex(z_curr);
	while (fractal->iter <= fractal->max_iter)
	{
		if (curr_abs > 2)
			break ;
		z_curr = add_complex(sqr_complex(z_curr), fractal->constant);
		curr_abs = abs_complex(z_curr);
		fractal->iter++;
	}
	fractal->z->x = z_curr.x;
	fractal->z->y = z_curr.y;
	put_pixel(fractal);
}
