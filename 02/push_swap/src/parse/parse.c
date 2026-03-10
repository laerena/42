#include "push_swap.h"

static void	parse_split_input(t_stack *a, char *arg)
{
	char	**tokens;
	int		i;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
		parse_fail(a, tokens);
	i = 0;
	while (tokens[i])
	{
		if (!push_token(a, tokens[i]))
			parse_fail(a, tokens);
		i++;
	}
	free_tokens(tokens);
}

static void	parse_args(t_stack *a, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!push_token(a, av[i]))
			parse_fail(a, NULL);
		i++;
	}
}

t_stack	*parse_stack_a(int ac, char **av)
{
	t_stack	*a;

	a = stack_init();
	if (!a)
		error_exit();
	if (ac < 2)
		return (a);
	if (ac == 2)
		parse_split_input(a, av[1]);
	else
		parse_args(a, ac, av);
	return (a);
}

/*
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
		if (!tokens || !tokens[0])
			parse_fail(a, tokens);
		i = 0;
		while (tokens[i])
		{
			if (!push_token(a, tokens[i]))
				parse_fail(a, tokens);
			i++;
		}
		free_tokens(tokens);
		return (a);
	}
	i = 1;
	while (i < ac)
	{
		if (!push_token(a, av[i]))
			parse_fail(a, NULL);
		i++;
	}
	return (a);
}
*/
