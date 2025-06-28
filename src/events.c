/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:23:33 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/25 12:02:45 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void ft_hook(void* param)
{
	t_data	*data; 
	double	move_factor;
	bool	should_redraw = false;

	data = (t_data *)param;
	move_factor = 0.04 * (data->max_real - data->min_real);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
	{
		data->min_imag += move_factor;
		data->max_imag += move_factor;
		should_redraw = true;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
	{
		data->min_imag -= move_factor;
		data->max_imag -= move_factor;
		should_redraw = true;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->min_real += move_factor;
		data->max_real += move_factor;
		should_redraw = true;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->min_real -= move_factor;
		data->max_real -= move_factor;
		should_redraw = true;
	}
	if (should_redraw)
		put_mandelbrot_fractal(data);
}

void scroll_hook(double xdelta, double ydelta, void *param)
{
	t_data *data;
	double zoom_intensity;
	double mouse_re;
	double mouse_im;
		
	data = (t_data *)param;
	zoom_intensity = 0.1;
		
	// Get mouse position
	int32_t mouse_x;
	int32_t mouse_y;
	mlx_get_mouse_pos(data->mlx, &mouse_x, &mouse_y);
		
	// Convert mouse position to complex plane coordinates
	mouse_re = data->min_real + (double)mouse_x * (data->max_real - data->min_real) / data->mlx->width;
	mouse_im = data->min_imag + (double)mouse_y * (data->max_imag - data->min_imag) / data->mlx->height;
		
	// Zoom in or out based on scroll direction
	if (ydelta > 0) // Zoom in
	{
		// Adjust boundaries to zoom in toward mouse position
		data->min_real = mouse_re - (1.0 - zoom_intensity) * (mouse_re - data->min_real);
		data->max_real = mouse_re + (1.0 - zoom_intensity) * (data->max_real - mouse_re);
		data->min_imag = mouse_im - (1.0 - zoom_intensity) * (mouse_im - data->min_imag);
		data->max_imag = mouse_im + (1.0 - zoom_intensity) * (data->max_imag - mouse_im);
	}
	else if (ydelta < 0) // Zoom out
	{
		// Adjust boundaries to zoom out from mouse position
		data->min_real = mouse_re - (1.0 + zoom_intensity) * (mouse_re - data->min_real);
		data->max_real = mouse_re + (1.0 + zoom_intensity) * (data->max_real - mouse_re);
		data->min_imag = mouse_im - (1.0 + zoom_intensity) * (mouse_im - data->min_imag);
		data->max_imag = mouse_im + (1.0 + zoom_intensity) * (data->max_imag - mouse_im);
	}
		
	// Redraw fractal with new boundaries
	put_mandelbrot_fractal(data);
}