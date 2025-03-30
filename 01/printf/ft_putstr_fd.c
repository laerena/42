/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:45:30 by lelai             #+#    #+#             */
/*   Updated: 2025/02/12 19:30:00 by lelai            ###   ########.fr       */
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
