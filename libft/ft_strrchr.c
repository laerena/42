/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:33:07 by leilai            #+#    #+#             */
/*   Updated: 2025/10/29 17:31:30 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = ft_strlen(s);
	if (cc == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == cc)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
