/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:40:05 by ebarbash          #+#    #+#             */
/*   Updated: 2024/10/26 12:40:32 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd) // -5
{
	long	number;
	char	digit;	

	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	digit = number % 10 + '0';
	if (number >= 0 && number <= 9)
	{
		write(fd, &digit, 1);
	}
	else
	{
		ft_putnbr_fd(number / 10, fd);
		write(fd, &digit, 1);
		digit = number % 10 + '0';
	}
}
