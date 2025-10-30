/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:57:24 by leilai            #+#    #+#             */
/*   Updated: 2025/10/29 17:57:25 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	result;

	if (!s)
		return (ft_putstr_fd("(null)", fd));
	i = 0;
	while (s[i])
	{
		result = ft_putchar_fd(s[i], fd);
		if (result == -1)
			return (-1);
		i++;
	}
	return (i);
}
