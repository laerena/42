/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlef.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:56:28 by leilai            #+#    #+#             */
/*   Updated: 2025/10/29 17:56:30 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_handlef(const char *format, va_list args, int *i)
{
	int	result;

	(*i)++;
	if (format[*i] == 's')
		result = ft_putstr_fd(va_arg(args, char *), 1);
	else if (format[*i] == 'c')
		result = ft_putchar_fd(va_arg(args, int), 1);
	else if (format[*i] == 'd' || format[*i] == 'i')
		result = ft_putnbr_fd(va_arg(args, int), 1);
	else if (format[*i] == 'x')
		result = ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef", 1);
	else if (format[*i] == 'X')
		result = ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", 1);
	else if (format[*i] == 'p')
		result = ft_putptr(va_arg(args, void *), 1);
	else if (format[*i] == '%')
		result = ft_putchar_fd('%', 1);
	else if (format[*i] == 'u')
		result = ft_putuint_fd(va_arg(args, unsigned int), 1);
	else
		result = ft_putchar_fd(format[*i], 1);
	return (result);
}
