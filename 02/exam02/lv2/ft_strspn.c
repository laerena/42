/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:55:16 by lelai             #+#    #+#             */
/*   Updated: 2025/03/28 15:46:25 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	size_t	check;

	i = 0;
	while (s[i])
	{
		j = 0;
		check = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
			{
				check = 1;
				break ;
			}
			j++;
		}
		if (!check)
			return (i);
		i++;
	}
	return (i);
}
/*
#include <string.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	printf("Initial numeric substring length: %zu\n", strspn(av[1], av[2]));
	printf("My output check: %zu\n", ft_strspn(av[1], av[2]));
}*/
