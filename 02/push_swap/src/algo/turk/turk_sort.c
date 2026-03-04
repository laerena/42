#include "push_swap.h"

/*
** circularly sorted during the algorithm:
** A is sorted if you rotate it until the minimum is on top
** eg. 3 4 5 1 2 is circularly sorted, but not sorted
** insert new values into A by rotating A to the 'correct gap'
**
** push everything except 3 from A to B
** sort 3 in A
** push back from B to A in the right order
*/

// reduse later cost by so smaller values are pushed first (bottom half of B)
static void	push_to_b(t_stack *a, t_stack *b)
{
	int	median;

	median = a->size / 2;
	while (a->size > 3)
	{
		if (a->top->index <= median)
			op_pb(a, b);
		else
			op_ra(a);
	}
}

int	pos_min(t_stack *a)
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

/*
** selection sort:

static void	push_to_b(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 3)
	{
		pos = pos_min(a);
		pos_to_top(a, pos, op_ra, op_rra);
		op_pb(a, b);
	}
}

** pos_min scan the list for ~O(n) comparisons each iteration
** rotate to bring min to top: up to about n/2 rotations per iteration
** worst case: O(n^2) ops
*/