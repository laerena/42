#include "push_swap.h"

static int	iabs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

// signed rotation cost: positive for rotate, negative for reverse r
static int	rot_cost(int size, int pos)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

// if costs have same sign rr/rrr can combine rotations
int	total_cost(int ca, int cb)
{
	if ((ca >= 0 && cb >= 0) || (ca <= 0 && cb <= 0))
	{
		if (iabs(ca) > iabs(cb))
			return (iabs(ca));
		return (iabs(cb));
	}
	return (iabs(ca) + iabs(cb));
}
