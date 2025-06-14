/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:02:51 by ebarbash          #+#    #+#             */
/*   Updated: 2024/10/26 12:34:25 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	if (!*little)
		return ((char *)big);
	while (big[start] != '\0' && start < len)
	{
		i = 0;
		while (big[start + i] == little[i] && (start + i) < len)
		{
			if (little[i + 1] == '\0')
				return ((char *)&big[start]);
			i++;
		}
		start++;
	}
	return (0);
}
