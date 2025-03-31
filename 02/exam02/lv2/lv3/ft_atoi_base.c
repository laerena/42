/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:53:35 by lelai             #+#    #+#             */
/*   Updated: 2025/04/01 00:16:12 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_base_value(char c, int base)
{
	int	i = 0;
	char	*digits = "0123456789abcedf";

	while (i < base) // loop through digits up to the given base
	{
		if (digits[i] == c || digits[i] - 32 == c) //check lower and upper
			return i;
		i++;
	}
	return -1;
}

int	ft_atoi_base(const char *str, int str_base)
{
	if (!str || str_base < 2 || str_base > 16) //check for invalid inputs
		return 0;
	int	result = 0;
	int	sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	int	value;
	while (*str)
	{
		value = get_base_value(*str, str_base);
		if (value == -1)
			break;
		result = result * str_base + value;
		str++;
	}
	return (result * sign);
}
