/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:08:06 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/24 22:47:57 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <../MLX42/include/MLX42/MLX42.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <linux/types.h>

#define WIDTH 1024
#define HEIGHT 1024

typedef struct s_complex // comples number kek
{
	double x;
	double y;
}	t_complex;

typedef struct s_data // to store both mlx and img instances
{
	mlx_t 		*mlx;
	mlx_image_t *img;
	double		min_real;
	double		max_real;
	double		min_imag;
	double		max_imag;
	double		zoom_factor;
}	t_data;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int32_t 	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int			error_check(mlx_t **mlx, mlx_image_t **img);
void		ft_hook(void* param);
void		scroll_hook(double xdelta, double ydelta, void *param);

bool		is_mandelbrot(double x, double y, unsigned int n);
void		put_mandelbrot_fractal(t_data *data);

// complex nums operations:
t_complex	zero();
t_complex	add_complex(t_complex c1, t_complex c2);
t_complex	multiply_complex(t_complex c1, t_complex c2);
double		abs_complex(t_complex c); // |c| = sqrt(x**2 + y**2) гипотенуза на плоскости комплексных чисел по факту