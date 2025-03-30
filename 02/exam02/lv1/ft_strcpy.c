/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:38:51 by lelai             #+#    #+#             */
/*   Updated: 2025/03/26 16:05:51 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char s2[] = "Hello, World";
	char s[50];
	char s1[50];
	
	strcpy(s, s2);
	ft_strcpy(s1, s2);
	printf("%s\n", s);
	printf("%s\n", s1);
	return (0);
}*/
