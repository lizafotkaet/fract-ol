/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:43:38 by ebarbash          #+#    #+#             */
/*   Updated: 2024/10/26 12:34:56 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	char	*ptr;
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	ptr = res;
	if (res == 0)
		return (0);
	while (*s && i < str_len + 1)
	{
		*ptr = f(i, *s);
		i++;
		s++;
		ptr++;
	}
	*ptr = '\0';
	return (res);
}
