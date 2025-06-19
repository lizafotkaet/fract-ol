/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:05:28 by sergei_pilm       #+#    #+#             */
/*   Updated: 2024/12/11 14:35:40 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"

int	put_number(int n)
{
	int		len;
	char	digit;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		len += put_number(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
	len++;
	return (len);
}

int	put_unsigned(unsigned int n)
{
	int		len;
	char	digit;

	len = 0;
	if (n >= 10)
		len += put_unsigned(n / 10);
	digit = n % 10 + '0';
	len += write(1, &digit, 1);
	return (len);
}

int	ft_print_hex(uintptr_t num, int flag)
{
	int		len;
	char	*hex_lower;
	char	*hex_upper;
	char	*hex;

	len = 0;
	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	if (flag == 1)
		hex = hex_upper;
	else
		hex = hex_lower;
	if (num >= 16)
		len += ft_print_hex(num / 16, flag);
	len += write(1, &hex[num % 16], 1);
	return (len);
}

int	ft_print_pointer(va_list args)
{
	void		*ptr;
	uintptr_t	address;
	int			len;

	ptr = va_arg(args, void *);
	address = (uintptr_t)ptr;
	if (address == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = 2;
	len += ft_print_hex(address, 0);
	return (len);
}

int	ft_print_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
