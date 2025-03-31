/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:25:17 by lelai             #+#    #+#             */
/*   Updated: 2025/03/31 23:47:00 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *s)
{
	int	i = 0;
	int	result = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0'); //number's ascii - 0 is number itself
		i++;
	}
	return result;
}

int	is_prime(int n)
{
	if (n < 2)
		return 0; //number < 2 not prime
	int	i = 2;

	while (i <= n / 2)
	{
		if (n % i == 0)//divisible not prime
			return (0);
		i++;
	}
	return (1);//no divisors found, it is prime
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	n = ft_atoi(av[1]);//convert input string to int
		
		if (n <= 0)
		{
			write (1, "0\n", 2);
			return 0;
		}
		int sum = 0;
		while (n > 0)
		{
			if (is_prime(n))
				sum += n;
			n--;
		}
		ft_putnbr(sum);
	}
	else write(1, "0", 1);
	write(1, "\n", 1);
	return 0;
}
