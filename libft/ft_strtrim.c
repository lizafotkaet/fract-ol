/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:10:24 by ebarbash          #+#    #+#             */
/*   Updated: 2024/10/26 16:52:48 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s);

static int	symbol_in_set(const char *set, char c)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	trim_start(const char *s, const char *set)
{
	size_t	move_start;

	move_start = 0;
	while (*s != '\0')
	{
		if (!symbol_in_set(set, *s))
			return (move_start);
		move_start++;
		s++;
	}
	return (move_start);
}

static size_t	trim_end(const char *s, const char *set)
{
	size_t	move_end;
	size_t	len;

	move_end = 0;
	len = ft_strlen(s);
	s += len - 1;
	while (len > 0)
	{
		if (!symbol_in_set(set, *s))
			return (move_end);
		move_end++;
		s--;
	}
	return (move_end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len_res;
	size_t		move_start;
	size_t		move_end;
	char		*res;
	char		*temp;

	move_start = trim_start(s1, set);
	move_end = trim_end(s1, set);
	len_res = ft_strlen(s1) - move_start - move_end;
	if (move_start + move_end >= ft_strlen(s1))
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char) * (len_res + 1));
	if (res == NULL)
		return (NULL);
	temp = res;
	s1 += move_start;
	while (len_res-- > 0)
		*(res++) = *(s1++);
	*res = '\0';
	return (temp);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char *str = ft_strtrim("  \t \t \n   \n\n\n\t", "");

// 	printf("HEHEHE");
// 	printf("%s", str);
// 	printf("HIHIHI");
// }
