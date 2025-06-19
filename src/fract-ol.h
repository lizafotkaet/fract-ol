/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:08:06 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/18 15:53:02 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <mlx.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <linux/types.h>

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_transparent_gradient(int color1, int color2, float mix);
void	make_circle(t_data *img, int x, int y, int radius, int color);
int 	close_win(t_vars *vars);