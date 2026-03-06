/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:37:51 by leilai            #+#    #+#             */
/*   Updated: 2026/03/06 16:37:52 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/*
** turning either style of input into an array of strings (tokens)
** eg. "3 2 1" -> ["3", "2", "1"]
*/

// check if token is a valid integer (optional sign + at least one digit)
static int	is_valid(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (0);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

// safe conversion with overflow/underflow error handling
static int	to_int(const char *s)
{
	long	sign;
	long	num;

	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	num = 0;
	while (*s)
	{
		num = num * 10 + (*s - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			error_exit();
		s++;
	}
	return ((int)(num * sign));
}

// check for duplicates in the stack (returns 1 if value is found)
static int	contains_value(t_stack *a, int value)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

// validates each, converts, dup-checks, pushes to stack
static void	push_token(t_stack *a, const char *tok)
{
	int		value;
	t_node	*node;

	if (!is_valid(tok))
		error_exit();
	value = to_int(tok);
	if (contains_value(a, value))
		error_exit();
	node = node_new(value);
	if (!node)
		error_exit();
	stack_push_bottom(a, node);
}

t_stack	*parse_stack_a(int ac, char **av)
{
	t_stack	*a;
	char	**tokens;
	int		i;

	a = stack_init();
	if (!a)
		error_exit();
	if (ac < 2)
		return (a);
	if (ac == 2)
	{
		tokens = ft_split(av[1], ' ');
		if (!tokens)
			error_exit();
		i = 0;
		while (tokens[i])
			push_token(a, tokens[i++]);
		free_tokens(tokens);
		return (a);
	}
	i = 1;
	while (i < ac)
		push_token(a, av[i++]);
	return (a);
}
