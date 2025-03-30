/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:29:33 by lelai             #+#    #+#             */
/*   Updated: 2025/03/27 15:43:56 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int		a;
	int		b;
	char	c;

	if (ac == 4)
	{
		a = atoi(av[1]);
		b = atoi(av[3]);
		c = av[2][0];
		if (c == '+')
			printf("%d", a + b);
		else if (c == '-')
			printf("%d", a - b);
		else if (c == '*')
			printf("%d", a * b);
		else if (c == '/')
			printf("%d", a / b);
	}
	printf("\n");
	return (0);
}
