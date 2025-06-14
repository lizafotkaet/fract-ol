/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:00:42 by ebarbash          #+#    #+#             */
/*   Updated: 2024/10/26 13:33:42 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;	

	d = (char *)dest;
	s = (const char *)src;
	if ((d == NULL && s == NULL) || n == 0)
		return (dest);
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}
