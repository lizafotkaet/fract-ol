/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:01:25 by ebarbash          #+#    #+#             */
/*   Updated: 2024/10/26 17:44:46 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res_str;
	char	*temp;
	size_t	len_total;

	len_total = ft_strlen(s1) + ft_strlen(s2) + 1;
	res_str = (char *)malloc(len_total * sizeof(char));
	if (res_str == NULL)
		return (NULL);
	temp = res_str;
	while (*s1)
		*res_str++ = *s1++;
	while (*s2)
		*res_str++ = *s2++;
	*res_str = '\0';
	return (temp);
}
