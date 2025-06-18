/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:08:10 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/06/18 06:11:35 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 300, 300, "КАКАШЕЧКА!!");
	if (!mlx || !mlx_win)
	{
		ft_putstr_fd("Error: Failed to initialize MLX or create window.\n", 2);
		return (EXIT_FAILURE);
	}
	mlx_loop(mlx);
}
