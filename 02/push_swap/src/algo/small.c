#include "push_swap.h"

static int	pos_min(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		pos;
	int		i;

	cur = a->top;
	min = cur->index; //initialize: smallest index found so far
	pos = 0;
	i = 0;
	//walk through the stack to find the smallest index and its position
	while (cur)
	{
		if (cur->index < min)
		{
			min = cur->index;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

void	sort_3(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->index;
	mid = a->top->next->index;
	bot = a->top->next->next->index;
	if (top > mid && top > bot)
		op_ra(a);
	else if (mid > top && mid > bot)
		op_rra(a);
	if (a->top->index > a->top->next->index)
		op_sa(a);
}

// bring position pos to the top using the cheapest direction
void	pos_to_top(
	t_stack *stack,
	int pos,
	void (*rotate)(t_stack *),
	void (*rev_rotate)(t_stack *)
)
{
	int	times;
	//if target pos is in the first half rotate up(ra) is cheaper
	if (pos <= stack->size / 2)
		while (pos-- > 0)
			rotate(stack);
	else
	{
		times = stack->size - pos;
		while (times-- > 0)
			rev_rotate(stack);
	}
}

void	small_sort(t_stack *a, t_stack *b)
{
	int	pos;

	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			op_sa(a);
		return ;
	}
	while (a->size > 3)
	{
		pos = pos_min(a);
		pos_to_top(a, pos, op_ra, op_rra);
		op_pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
		op_pa(a, b);
}
