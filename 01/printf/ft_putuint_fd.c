/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:57:28 by leilai            #+#    #+#             */
/*   Updated: 2025/10/29 17:57:29 by leilai           ###   ########.fr       */
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
