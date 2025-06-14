/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:11:07 by ebarbash          #+#    #+#             */
/*   Updated: 2024/10/28 12:51:58 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*temp;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		res = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		res = malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	temp = res;
	s += start;
	while (len-- > 0 && *s)
		*(res++) = *(s++);
	*res = '\0';
	return (temp);
}
