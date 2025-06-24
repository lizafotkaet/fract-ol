/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:53:06 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/24 22:27:02 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

t_complex	add_complex(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.x = c1.x + c2.x;
	result.y = c1.y + c2.y;
	return (result);
}

t_complex	multiply_complex(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.x = c1.x * c2.x - c1.y * c2.y;
	result.y = c1.x * c2.y + c1.y * c2.x;
	return (result);
}

double	abs_complex(t_complex c)
{
	double	abs;

	abs = sqrt(c.x * c.x + c.y * c.y);
	return (abs);
}

t_complex	zero()
{
	t_complex	z;
	z.x = 0;
	z.y = 0;
	return (z);
}
