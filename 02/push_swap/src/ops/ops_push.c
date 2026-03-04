#include "push_swap.h"

/*
** internal primative: move the top node of src to the top of dst
** do nothing if empty stack
** so, return 1 if node was moved, 0 if nothing happend
*/
static int	push_stack(t_stack *src, t_stack *dst)
{
	t_node	*node;

	node = NULL;
	if (!src || !dst || src->size == 0)
		return (0);
	node = stack_pop_top(src);
	stack_push_top(dst, node);
	return (1);
}

void	op_pb(t_stack *a, t_stack *b)
{
	if (push_stack(a, b))
		write(1, "pb\n", 3);
}

void	op_pa(t_stack *a, t_stack *b)
{
	if (push_stack(b, a))
		write(1, "pa\n", 3);
}