/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:56:10 by leilai            #+#    #+#             */
/*   Updated: 2025/10/29 17:56:13 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	process_format(const char *format, va_list args, int *i, int *count)
{
	int	result;

	if (format[*i] == '%' && format[*i + 1])
	{
		result = ft_handlef(format, args, i);
		if (result == -1)
			return (-1);
		*count += result;
	}
	else
	{
		result = ft_putchar_fd(format[*i], 1); 
		if (result == -1)
			return (-1);
		*count += result;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		result;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		result = process_format(format, args, &i, &count);
		if (result == -1)
		{
			va_end(args);
			return (-1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
