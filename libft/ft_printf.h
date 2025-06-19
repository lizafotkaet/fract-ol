/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:21:56 by ebarbash          #+#    #+#             */
/*   Updated: 2025/02/24 14:13:48 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		print_args(va_list args, const char *str);
int		put_number(int n);
int		put_unsigned(unsigned int n);
int		ft_print_hex(uintptr_t num, int flag);
int		ft_print_pointer(va_list args);
int		ft_print_str(va_list args);
int		putchr(int c);
void	ft_putstr_fd(char *s, int fd);
int		num_len(int n);

#endif