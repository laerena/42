/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:32:23 by lelai             #+#    #+#             */
/*   Updated: 2024/11/26 17:32:10 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	while (len > 0)
	{
		*(tmp++) = (unsigned char)c;
		len--;
	}
	return (str);
}
