/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:53:06 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/07/29 03:01:18 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

t_complex	add_complex(t_complex c1, t_complex *c2)
{
	t_complex	result;

	result.x = c1.x + c2->x;
	result.y = c1.y + c2->y;
	return (result);
}

t_complex	multiply_complex(t_complex *c1, t_complex *c2)
{
	t_complex	result;

	result.x = c1->x * c2->x - c1->y * c2->y;
	result.y = c1->x * c2->y + c1->y * c2->x;
	return (result);
}

t_complex	sqr_complex(t_complex c)
{
	t_complex	result;

	result.x = c.x * c.x - c.y * c.y;
	result.y = c.x * c.y + c.y * c.x;
	return (result);
}

// |c| = sqrt(x**2 + y**2)

double	abs_complex(t_complex c)
{
	double	abs;

	abs = sqrt(c.x * c.x + c.y * c.y);
	return (abs);
}

t_complex	*zero(t_complex *c)
{
	c->x = 0;
	c->y = 0;
	return (c);
}
