/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:50:43 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/17 18:48:31 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

static int	word_count(const char *s, char c)
{
	int	arr_len;
	int	flag;

	arr_len = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			arr_len++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (arr_len);
}

static int	ft_word_len(const char *s, char c)
{
	int	wordlen;

	wordlen = 0;
	while (*s && *s != c)
	{
		if (*s == c)
			return (wordlen);
		wordlen++;
		s++;
	}
	return (wordlen);
}

static void	free_all(char	**arr, int arr_len)
{
	int	i;

	i = 0;
	while (i < arr_len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		arr_len;
	int		word_len;
	int		i;

	arr_len = word_count(s, c);
	arr = malloc(sizeof(char *) * (arr_len + 1));
	if (arr == NULL)
		return (NULL);
	word_len = 0;
	i = 0;
	while (i < arr_len)
	{
		while (*s == c)
			s++;
		word_len = ft_word_len(s, c);
		arr[i] = ft_substr(s, 0, word_len);
		s += word_len;
		word_len = 0;
		if (!arr[i])
			return (free_all(arr, i), NULL);
		i++;
	}
	arr[arr_len] = NULL;
	return (arr);
}
