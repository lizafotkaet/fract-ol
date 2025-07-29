/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:08:06 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/07/29 03:24:51 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <linux/types.h>

#define SIZE 750
#define C_REAL -0.8
#define C_IMAG 0.156
#define MLX_ERR 5
#define IMG_ERR 6

typedef struct s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}	t_rgba;

typedef struct s_palette
{
	uint8_t		count;
	int			cycle;
	int			colors[16];
}	t_palette;

typedef union u_color
{
	int			value;
	t_rgba		rgba;
}	t_color;

typedef struct s_complex
{
	double		x;
	double		y;
}	t_complex;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			type;
	t_complex	*constant;
	t_complex	*z;
	t_complex	*pixel;
	t_complex	*complex;
	t_complex	*limit;
	t_complex	*center;
	int			iter;
	int			max_iter;
	t_palette	*palette;
	int			palette_index;
	int			palette_len;
	bool		smooth;
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

// init fts
void		check_input(int argc, char** argv, t_data *fractal, int *error);
void		init_image(t_data *fractal);
// complex nums operations:
t_complex	*zero();
t_complex	add_complex(t_complex c1, t_complex *c2);
t_complex	multiply_complex(t_complex *c1, t_complex *c2);
t_complex	sqr_complex(t_complex c);
double		abs_complex(t_complex c);
// events
void		get_hook(void *data);
void		scroll_hook(double xdelta, double ydelta, void *param);
void		arrow_keys(int key, t_data *fractal);
void		key_hook(mlx_key_data_t keydata, void *param);
//img stuff
void		init_image(t_data *fractal);
void		fract_data_init(t_data *fractal);
//fractals stuff
void		draw_fractal(t_data *fractal);
void		mandelbrot(t_data *fractal);
void		julia(t_data *fractal);
//colors stuff
void		put_pixel(t_data *fractal);
int			pallete_len(t_data *fractal);
t_palette	*get_palettes(void);
int			pallete_len(t_data *fractal);
t_color		get_color_struct(t_data *fractal);
// utils
void		use_msg(t_data *fractal);
void		error_exit(t_data *fractal, int err);
char		*fract_name(int type);
void		ft_malloc(t_data **fractal);
void 		ft_free(t_data *fractal);
void		terminate(t_data *fractal);
