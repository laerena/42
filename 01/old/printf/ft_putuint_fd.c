/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:10:00 by lelai             #+#    #+#             */
/*   Updated: 2025/02/12 18:10:00 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint_fd(unsigned int n, int fd)
{
	int		count;
	char	c;
	int		result;

	count = 0;
	if (n >= 10)
	{
		result = ft_putuint_fd(n / 10, fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	c = (n % 10) + '0';
	result = ft_putchar_fd(c, fd);
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}
