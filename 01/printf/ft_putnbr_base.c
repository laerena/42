/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:00:10 by lelai             #+#    #+#             */
/*   Updated: 2025/02/12 20:10:00 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr_base(unsigned int n, char *base, int fd)
{
	int		count;
	int		base_len;
	int		result;

	count = 0;
	base_len = ft_strlen(base);
	if (n >= (unsigned int)base_len)
	{
		result = ft_putnbr_base(n / base_len, base, fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar_fd(base[n % base_len], fd);
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}
