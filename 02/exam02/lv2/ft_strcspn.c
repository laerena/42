/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:59:07 by lelai             #+#    #+#             */
/*   Updated: 2025/03/31 15:20:46 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

#include <string.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	printf("First occurrence of \"%s\" at index: %zu\n", av[2], strcspn(av[1], av[2]));
	printf("My output check: %zu\n", ft_strcspn(av[1], av[2]));
}
