/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:38:00 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/24 22:32:14 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

// Mika's function:

void	putpixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
{
	uint32_t	*pixels;

	pixels = (uint32_t *)img->pixels;
	pixels[y * img->width + x] = color;
}

int	create_transparent_gradient(int color1, int color2, float mix)
{
	int	r;
	int	g;
	int	b;
	
	r = (int)((1 - mix) * ((color2 >> 16) & 0xFF) + mix * ((color1 >> 16) & 0xFF));
	g = (int)((1 - mix) * ((color2 >> 8) & 0xFF) + mix * ((color1 >> 8) & 0xFF));
	b = (int)((1 - mix) * (color2 & 0xFF) + mix * (color1 & 0xFF));
	
	return (r << 16 | g << 8 | b);
}

void	make_square(mlx_image_t* img, uint32_t x, uint32_t y, uint32_t size, uint32_t color)
{
	uint32_t nx;
	uint32_t ny;
	
	nx = 0;
	ny = 0;

	while (nx < size)
	{
		while (ny < size)
		{
			putpixel(img, x + nx, y + ny, color);
			ny++;
		}
		ny = y;
		nx++;
	}
}
static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel
			(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}
