/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:37:31 by lelai             #+#    #+#             */
/*   Updated: 2024/11/23 20:10:35 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *a, const char *b, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (b[0] == '\0' || b == NULL)
		return ((char *)a);
	while (a[i] != '\0' && i < n)
	{
		if (a[i] == b[j])
		{
			while (a[i + j] == b[j] && i + j < n)
			{
				if (b[j + 1] == '\0')
					return ((char *)a + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
