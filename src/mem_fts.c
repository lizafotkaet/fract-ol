/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:50:28 by ebarbash          #+#    #+#             */
/*   Updated: 2025/07/29 11:53:32 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	ft_malloc_null(t_data **fractal)
{
	(*fractal)->pixel = NULL;
	(*fractal)->complex = NULL;
	(*fractal)->center = NULL;
	(*fractal)->z = NULL;
	(*fractal)->limit = NULL;
	(*fractal)->constant = NULL;
	(*fractal)->img = NULL;
	(*fractal)->mlx = NULL;
	(*fractal)->palette = NULL;
}

void	ft_malloc(t_data **fractal)
{
	*fractal = malloc(sizeof(t_data));
	if (!*fractal)
		exit(EXIT_FAILURE);
	ft_malloc_null(fractal);
	(*fractal)->pixel = malloc(sizeof(t_complex));
	(*fractal)->complex = malloc(sizeof(t_complex));
	(*fractal)->center = malloc(sizeof(t_complex));
	(*fractal)->z = malloc(sizeof(t_complex));
	(*fractal)->limit = malloc(sizeof(t_complex));
	(*fractal)->constant = malloc(sizeof(t_complex));
	(*fractal)->palette = malloc(sizeof(t_palette));
	if (!(*fractal)->limit || !(*fractal)->pixel
		|| !(*fractal)->complex || !(*fractal)->center
		|| !(*fractal)->z || !(*fractal)->constant || !(*fractal)->palette)
	{
		ft_free(*fractal);
		exit(EXIT_FAILURE);
	}
}

void	ft_free(t_data *fractal)
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
