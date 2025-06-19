/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:27:10 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/02/24 14:11:35 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"

int	num_len(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	putchr(int c)
{
	write(1, &c, 1);
	return (1);
}
