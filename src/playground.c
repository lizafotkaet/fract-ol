/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:38:00 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/18 15:12:32 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	make_square(t_data *img, int x, int y, int size, int color)
{
	int	i;
	int	j;
	int	half;
	int	start_x;
	int	start_y;

	half = size / 2;
	start_x = x - half;
	start_y = y - half;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(img, start_x + i, start_y + j, color);
			j++;
		}
		i++;
	}
}

void	make_circle(t_data *img, int x, int y, int radius, int color)
{
	int	i;
	int	j;
	int	distance;
	int	gradient_color;
	float	intensity;

	i = x - radius;
	while (i <= x + radius)
	{
		j = y - radius;
		while (j <= y + radius)
		{
			distance = (i - x) * (i - x) + (j - y) * (j - y);
			if (distance <= radius * radius)
			{
				intensity = 1.0f - (float)sqrt(distance) / radius;
				gradient_color = create_transparent_gradient(color, 0x00000000, intensity);
				my_mlx_pixel_put(img, i, j, gradient_color);
			}
			j++;
		}
		i++;
	}
}