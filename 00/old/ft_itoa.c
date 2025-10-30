/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:56:06 by lelai             #+#    #+#             */
/*   Updated: 2024/11/28 17:44:33 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long nbr);

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*result;

	nbr = n;
	len = ft_intlen(nbr);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		result[0] = '0';
	while (nbr != 0)
	{
		result[len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (result);
}

static int	ft_intlen(long nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
	{
		count++;
		nbr *= -1;
	}	
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

/*
#include <stdio.h>
int	main(void)
{
	int	n = -57427;
	printf("%d\n", ft_intlen(n));
	printf("%s\n", ft_itoa(n));
}
*/