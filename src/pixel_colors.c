/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:03:19 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/07/29 04:04:26 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static int	ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static t_color	clerp(t_color c1, t_color c2, double p)
{
	t_color	c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0xFF;
	return (c);
}

static t_color	linear_color(double i, int max, t_palette *p)
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

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	put_pixel(t_data *fractal)
{
	t_color	col_struct; //
	int		color;

	if (fractal->iter >= fractal->max_iter)
		mlx_put_pixel(fractal->img, fractal->pixel->x, fractal->pixel->y, 0x000000FF);
	else
	{
		col_struct = get_color_struct(fractal);
		color = get_rgba(col_struct.rgba.r,
				col_struct.rgba.g,
				col_struct.rgba.b, col_struct.rgba.a);
		mlx_put_pixel(fractal->img, fractal->pixel->x, fractal->pixel->y, color);
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

t_color	get_color_struct(t_data *fractal)
{
	return (linear_color(fractal->iter, fractal->max_iter, fractal->palette));
}
