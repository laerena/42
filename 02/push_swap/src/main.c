#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	// parse input into stack a and initialize stack b
	a = parse_stack_a(ac, av);
	b = stack_init();
	if (!b)
	{
		stack_clear(a);
		error_exit();
	}

	// if already sorted, do nothing (print nothing)
	if (is_sorted(a))
	{
		stack_clear(a);
		stack_clear(b);
		return (0);
	}

	// sort(a, b);
	normalize_stack(a);
	if (a->size <= 5)
		small_sort(a, b);
	else
	{
	#ifdef USE_CHUNK
		chunk_sort(a, b);
	#else
		radix_sort(a, b);
	#endif
	}

	// cleanup
	stack_clear(a);
	stack_clear(b);
	return (0);
}
