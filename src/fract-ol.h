/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:08:06 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/20 13:22:20 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <../mlx/include/MLX42/MLX42.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <linux/types.h>

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}	t_vars;

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

int		create_transparent_gradient(int color1, int color2, float mix);
int 	close_win(t_vars *vars);
void	putpixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color);
void	make_square(mlx_image_t* img, uint32_t x, uint32_t y, uint32_t size, uint32_t color);