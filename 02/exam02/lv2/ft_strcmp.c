/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:51:43 by lelai             #+#    #+#             */
/*   Updated: 2025/03/27 15:56:49 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_strcmp("abc", "abc"));  // 0
	printf("%d\n", ft_strcmp("abc", "abd"));  // neg
	printf("%d\n", ft_strcmp("abd", "abc"));  // postive
	printf("%d\n", ft_strcmp("abc", "a"));    // postive
	printf("%d\n", ft_strcmp("a", "abc"));    // neg
	return 0;
}*/
