/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:39:25 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/07/29 12:05:40 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	error_exit(t_data *fractal, int err)
{
	if (err == MLX_ERR)
	{
		free(fractal);
		exit(EXIT_FAILURE);
	}
	if (err == IMG_ERR)
	{
		mlx_terminate(fractal->mlx);
		free(fractal);
		exit(EXIT_FAILURE);
	}
}

char	*fract_name(int type)
{
	if (type == 1)
		return ("Mandelbrot set");
	else if (type == 2)
		return ("Julia set");
	else
		return ("fract-ol");
}

void	use_msg(t_data *fractal)
{
	ft_printf("Available options are:\n1: Mandelbrot\n");
	ft_printf("2: Julia (+ 2 arguments for the c constant)\n");
	ft_printf("\tNOTE invalid constant arguments are treated like zero\n");
	ft_free(fractal);
	exit(EXIT_FAILURE);
}

void	terminate(t_data *fractal)
{
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_terminate(fractal->mlx);
	ft_free(fractal);
}
