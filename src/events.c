/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:51:11 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/07/29 04:02:13 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	arrow_keys(int key, t_data *fractal)
{
	double	h;
	double	w;

	w = (fractal->limit->x * 2.0) * fractal->zoom_factor;
	h = (fractal->limit->y * 2.0) * fractal->zoom_factor;
	if (key == MLX_KEY_LEFT)
		fractal->center->x += w * 0.02;
	if (key == MLX_KEY_RIGHT)
		fractal->center->x -= w * 0.02;
	if (key == MLX_KEY_UP)
		fractal->center->y -= h * 0.02;
	if (key == MLX_KEY_DOWN)
		fractal->center->y += h * 0.02;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*fractal;

	fractal = (t_data *)param;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_RELEASE)
		fractal->palette = &fractal->palette[fractal->palette_index++ % fractal->palette_len];
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_data		*fractal;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		movex;
	double		movey;

	fractal = (t_data *)param;
	(void)xdelta;
	mlx_get_mouse_pos(fractal->mlx, &mouse_x, &mouse_y);
	if (mouse_x < 0 || mouse_x >= SIZE || mouse_y < 0 || mouse_y >= SIZE)
		return ;
	movex = (mouse_x - SIZE / 2.0) * fractal->zoom_factor / SIZE;
	movey = (mouse_y - SIZE / 2.0) * fractal->zoom_factor / SIZE;
	if (ydelta > 0)
		fractal->zoom_factor *= 1.1;
	else if (ydelta < 0)
		fractal->zoom_factor /= 1.1;
	fractal->center->x += movex - (mouse_x - SIZE / 2.0) * fractal->zoom_factor / SIZE;
	fractal->center->y += movey - (mouse_y - SIZE / 2.0) * fractal->zoom_factor / SIZE;
}

void	get_hook(void *param)
{
	t_data	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_I))
		fractal->max_iter = (fractal->max_iter * 1.1) + 1;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_D))
		fractal->max_iter /= 1.1;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_Z))
		fractal->zoom_factor *= 1.1;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_X))
		fractal->zoom_factor /= 1.1;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		arrow_keys(MLX_KEY_DOWN, fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		arrow_keys(MLX_KEY_UP, fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		arrow_keys(MLX_KEY_RIGHT, fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		arrow_keys(MLX_KEY_LEFT, fractal);
	mlx_scroll_hook(fractal->mlx, &scroll_hook, fractal);
	mlx_key_hook(fractal->mlx, &key_hook, fractal);
	draw_fractal(fractal);
}
