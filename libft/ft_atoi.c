/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:39:10 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/24 00:33:51 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *nptr, int *error)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		nptr++;
	}
	return (num * sign);
}

// #include <limits.h>
// 
// int	main(int argc, char **argv)
// {
// 	// char	*str = "    +2147483647";
// 	int		nbr;
// 	int		error = 0;
// 
// 	// long long	number;
// 
// 	// number = 9223372036854775807;
// 	// // printf("%ld\n", number);
// 	// number = number + number;
// 
// 	// printf("%ld\n", number);
// 
// 	if (argc != 2)
// 		return (-1);
// 	nbr = ft_atoi(argv[1], &error);
// 	if (error == 1)
// 		printf("Out of range\n");
// 	else
// 		printf("%d\n", nbr);
// 	return (0);
// }