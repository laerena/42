#include "push_swap.h"

/*
** during rebuild phase we want to push back the largest remaining elemengt first
** ensures A rebuilds in ascending order
*/
static int	pos_max(t_stack *b)
{
	t_node	*cur;
	int		max;
	int		pos;
	int		i;

	cur = b->top;
	max = cur->index; // initialize: largest index found so far
	pos = 0;
	i = 0;
	// walk through the stack to find the largest index and its position
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

static int	chunk_size(int n)
{
	if (n <= 100)
		return (20);
	else
		return (45);
}

static void	push_chunks(t_stack *a, t_stack *b, int chunk)
{
	int	limit;
	int	pushed;

	limit = chunk - 1;
	pushed = 0;
	while (a->size > 0)
	{
		// if belongs in current chunk push to b
		if (a->top->index <= limit)
		{
			op_pb(a, b);
			pushed++;
			// bury smaller half of chunk in b to minimize moves during rebuild
			if (b->top->index <= limit - (chunk / 2))
				op_rb(b);
			// when we have pushed a full chunk
			// increase teh range to next chunk
			// this is made possible by normalization
			if (pushed % chunk == 0)
				limit += chunk;
		}
		else
			op_ra(a);
	}
}


// always bring maximum element in b to top and push it to a
static void	rebuild(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->size > 0)
	{
		pos = pos_max(b);
		pos_to_top(b, pos, op_rb, op_rrb);
		op_pa(a, b);
	}
}

/*
** determine chunk size
** push values in chunks to b
** push back from b to a in sorted order
** divide & reassemble
*/
void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk;

	chunk = chunk_size(a->size);
	push_chunks(a, b, chunk);
	rebuild(a, b);
}
