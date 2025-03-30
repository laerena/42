/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:50:15 by lelai             #+#    #+#             */
/*   Updated: 2025/02/12 21:15:00 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recursive(unsigned int n, int fd)
{
	int		count;
	char	c;
	int		result;

	count = 0;
	if (n >= 10)
	{
		result = ft_putnbr_recursive(n / 10, fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	c = (n % 10) + '0';
	result = ft_putchar_fd(c, fd);
	if (result == -1)
		return (-1);
	return (count + result);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	count;
	int	result;

	count = 0;
	if (n < 0)
	{
		result = ft_putchar_fd('-', fd);
		if (result == -1)
			return (-1);
		count += result;
		n = -n;
	}
	return (count + ft_putnbr_recursive((unsigned int)n, fd));
}
