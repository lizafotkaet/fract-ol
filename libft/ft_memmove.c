/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:56:45 by ebarbash          #+#    #+#             */
/*   Updated: 2024/10/26 14:01:47 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if ((d == NULL && s == NULL) || n == 0)
		return (dest);
	if (d > s && d < s + n)
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	src[] = "123456789";
// 	// char	dest[10];

// 	ft_memmove(src + 2, src, 5);
// 	printf("%s\n", src); //121234589
// 	return (0);
// }
