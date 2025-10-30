/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:33:22 by lelai             #+#    #+#             */
/*   Updated: 2025/02/12 17:02:31 by lelai            ###   ########.fr       */
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
