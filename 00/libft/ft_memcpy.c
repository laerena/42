/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:59:59 by lelai             #+#    #+#             */
/*   Updated: 2024/11/23 14:23:33 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dest && !src)
		return (dest);
	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
