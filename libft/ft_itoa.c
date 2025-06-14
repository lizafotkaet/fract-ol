/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:51:24 by ebarbash          #+#    #+#             */
/*   Updated: 2024/10/28 12:51:27 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	arr_len(long n)
{
	int	num_len;

	num_len = 0;
	if (n <= 0)
	{
		num_len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		num_len++;
	}
	return (num_len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		len;

	num = n;
	len = arr_len(num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (num < 0)
		num = -num;
	while (len--)
	{
		res[len] = num % 10 + '0';
		num /= 10;
		if (num == 0 && n >= 0)
			break ;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
// int	main(void)
// {
//	 printf("%d\n", arr_len(0));
//		printf("%s\n", ft_itoa(-3));
// //	 // printf("%s\n", itoa(123));
//	 printf("%s\n", ft_itoa(3));
// //	 // printf("%s\n", itoa(0));
// //	 printf("%s\n", ft_itoa(-2147483648));
// //	 // printf("%s\n", itoa(-2147483648));
// //	 printf("%s\n", ft_itoa(2147483647));
// //	 // printf("%s\n", itoa(2147483648));
// //	 printf("%s\n", ft_itoa(2147483648));
// }