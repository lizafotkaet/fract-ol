/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:48:25 by ebarbash          #+#    #+#             */
/*   Updated: 2025/07/29 12:09:03 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

t_color	linear_color(double i, int max, t_palette *p)
{
	double		index;
	double		adjust;
	int			c;

	if (p->cycle)
		index = fmod(i, p->cycle - 1) / (p->cycle - 1);
	else
		index = i / max;
	c = p->count - 1;
	adjust = fmod(index, 1.0 / c) * c;
	return (clerp((t_color)(p->colors[(int)(index * c) + 1]),
		(t_color)(p->colors[(int)(index * c)]),
		(int)(adjust + 1) - adjust));
}

void	put_pixel(t_data *fractal)
{
	t_color	col_struct;
	int		color;

	if (fractal->iter >= fractal->max_iter)
		mlx_put_pixel(fractal->img,
			fractal->pixel->x, fractal->pixel->y, 0x000000FF);
	else
	{
		col_struct = linear_color(fractal->iter,
				fractal->max_iter, fractal->palette);
		color = get_rgba(col_struct.rgba.r,
				col_struct.rgba.g,
				col_struct.rgba.b, col_struct.rgba.a);
		mlx_put_pixel(fractal->img,
			fractal->pixel->x, fractal->pixel->y, color);
	}
}

t_palette	*get_palettes(void)
{
	static t_palette	array[3];

	array[0]
		= (t_palette){5, 0, {0x2C3E50, 0x8E44AD, 0x3498DB, 0x16A085, 0xF1C40F}};
	array[1]
		= (t_palette){5, 0, {0xD35400, 0xC0392B, 0x7D3C98, 0x2ECC71, 0x1ABC9C}};
	array[2]
		= (t_palette){5, 0, {0x34495E, 0xE74C3C, 0x9B59B6, 0x2980B9, 0x27AE60}};
	return (array);
}

int	pallete_len(t_data *fractal)
{
	int	i;

	i = 0;
	while (fractal->palette[i].count)
		i++;
	return (i);
}
