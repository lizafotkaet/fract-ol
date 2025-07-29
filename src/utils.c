/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:39:25 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/07/29 02:54:24 by sergei_pilm      ###   ########.fr       */
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
	ft_printf("2: Julia (+ 2 arguments for the c constant)");
	ft_free(fractal);
	exit(EXIT_FAILURE);
}

void	ft_malloc(t_data **fractal)
{
	*fractal = malloc(sizeof(t_data));
	if (!*fractal)
		exit(EXIT_FAILURE);
	(*fractal)->pixel = NULL;
	(*fractal)->complex = NULL;
	(*fractal)->center = NULL;
	(*fractal)->z = NULL;
	(*fractal)->limit = NULL;
	(*fractal)->constant = NULL;
	(*fractal)->img = NULL;
	(*fractal)->mlx = NULL;
	(*fractal)->palette = NULL;
	(*fractal)->pixel = malloc(sizeof(t_complex));
	(*fractal)->complex = malloc(sizeof(t_complex));
	(*fractal)->center = malloc(sizeof(t_complex));
	(*fractal)->z = malloc(sizeof(t_complex));
	(*fractal)->limit = malloc(sizeof(t_complex));
	(*fractal)->constant = malloc(sizeof(t_complex));
	(*fractal)->palette = malloc(sizeof(t_palette));
	if (!(*fractal)->limit || !(*fractal)->pixel || 
		!(*fractal)->complex || !(*fractal)->center || 
			!(*fractal)->z || !(*fractal)->constant || !(*fractal)->palette)
	{
		ft_free(*fractal);
		exit(EXIT_FAILURE);
	}
}

void ft_free(t_data *fractal)
{
	if (!fractal)
		return ;
	if (fractal->limit != NULL)
		free(fractal->limit);
	if (fractal->pixel != NULL)
		free(fractal->pixel);
	if (fractal->complex != NULL)
		free(fractal->complex);
	if (fractal->constant != NULL)
		free(fractal->constant);
	if (fractal->center != NULL)
		free(fractal->center);
	if (fractal->z != NULL)
		free(fractal->z);
	if (fractal->palette != NULL)
		free(fractal->palette);
	if (fractal->img != NULL)
		mlx_delete_image(fractal->mlx, fractal->img);
	if (fractal->mlx != NULL)
		mlx_terminate(fractal->mlx);
	free(fractal);
}

void	terminate(t_data *fractal)
{
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_terminate(fractal->mlx);
	ft_free(fractal);
}
