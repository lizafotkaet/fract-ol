/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:15:59 by ebarbash          #+#    #+#             */
/*   Updated: 2024/12/11 14:13:33 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"

int	print_args(va_list args, const char *str)
{
	int		len;

	len = 0;
	if (*str == 'c')
		len += putchr(va_arg(args, int));
	else if (*str == 'i' || *str == 'd')
		len += put_number(va_arg(args, int));
	else if (*str == 'p')
		len += ft_print_pointer(args);
	else if (*str == 'u')
		len += put_unsigned(va_arg(args, unsigned int));
	else if (*str == 'x')
		len += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (*str == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (*str == 's')
		len += ft_print_str(args);
	else if (*str == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				len += print_args(args, format);
			else
				return (-1);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}
