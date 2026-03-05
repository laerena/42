#include "push_swap.h"
#include "turk.h"

// find the position of the smallest index that is bigger than idx
static int	successor_pos(t_stack *a, int idx)
{
	t_node	*cur;
	int		best;
	int		pos;
	int		i;

	cur = a->top;
	best = 2147483647;//sentinel: no successor found yet
	pos = -1;
	i = 0;
	while (cur)
	{
		if (cur->index > idx && cur->index < best)
		//each time we find a better successor, update best and pos
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
int	target_pos(t_stack *a, int idx)
{
	int	pos;

	pos = successor_pos(a, idx);
	if (pos != -1) //successor exists
		return (pos);
	return (pos_min(a));
}
/*
int	chunk_size(int n)
{
	if (n <= 100)
		return (20);
	return (45);
}
*/