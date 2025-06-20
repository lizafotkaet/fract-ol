/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:38:00 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/20 13:22:12 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

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
