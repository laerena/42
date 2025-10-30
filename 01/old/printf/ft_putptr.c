/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:07:09 by lelai             #+#    #+#             */
/*   Updated: 2025/03/16 14:07:25 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_helper(unsigned long ptr, int fd)
{
	int		count;
	char	*base;
	int		result;

	base = "0123456789abcdef";
	count = 0;
	if (ptr >= 16)
	{
		result = ft_putptr_helper(ptr / 16, fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar_fd(base[ptr % 16], fd);
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}

int	ft_putptr(void *ptr, int fd)
{
	int	result;

	if (ptr == NULL)
	{
		result = ft_putstr_fd("(nil)", fd);
		if (result == -1)
			return (-1);
		return (result);
	}
	result = ft_putstr_fd("0x", fd);
	if (result == -1)
		return (-1);
	if (ptr == NULL)
		return (result + ft_putchar_fd('0', fd));
	return (result + ft_putptr_helper((unsigned long)ptr, fd));
}
