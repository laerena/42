#include "push_swap.h"

// find the position of the smallest index that is bigger than idx
static int	successor_pos(t_stack *a, int idx)
{
	t_node	*cur;
	int		best;
	int		pos;
	int		i;

	cur = a->top;
	best = 2147483647;//initialize: best candidate for target position
	pos = -1;
	i = 0;
	while (cur)
	{
		if (if cur->index > idx && cur->index < best)
		{
			best = cur->index;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

/*
** implement successor and wrap around
** find and rotate smallest index to top if no bigger index (successor) found
** in order to insert idx before
*/
static int	target_pos(t_stack *a, int idx)
{
	int	pos;

	pos = successor_pos(a, idx);
	if (pos != -1)
		return (pos);
	return (pos_min(a));
}

// signed rotation cost: positive for rotate, negative for reverse r
static int	rot_cost(int size, int pos)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

