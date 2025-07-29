/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:11:36 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/07/29 12:11:26 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

double	ft_atof(const char *str)
{
	int		whole;
	double	fraction;
	char	*temp;
	int		error;

	error = 0;
	whole = ft_atoi(str, &error);
	temp = ft_strchr(str, '.');
	if (!temp)
		temp = ft_strchr(str, ',');
	if (!temp)
		return (whole);
	temp++;
	fraction = ft_atoi(temp, &error);
	while (*temp && *temp >= '0' && *temp <= '9')
	{
		fraction /= 10;
		temp++;
	}
	if (whole < 0)
		return (whole - fraction);
	return (whole + fraction);
}
