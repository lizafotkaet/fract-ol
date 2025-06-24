/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:36:33 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/24 21:43:45 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"






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