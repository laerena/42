/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:39:19 by lelai             #+#    #+#             */
/*   Updated: 2025/03/28 15:45:22 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c);
int	ft_isdigit(int c);

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	const char	*test = "320";
	int	result = 0;
	int	i = 0;
	
	printf("Coverting: \"%s\"\n", test);
	while (test[i])
	{
		result = result * 10 + (test[i] - 48);
		printf("Step %d: Read '%c' (ASCII : %d) → result = %d\n", i + 1, test[i], test[i], result);
		i++;
	}
	printf("Final result: %d\n", ft_atoi(test));
	return (0);
}*/
