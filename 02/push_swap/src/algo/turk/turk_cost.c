#include "push_swap.h"

static int	iabs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

/*
**signed rotation cost: positive for rotate, negative for reverse r
** +k  => rotate k times (ra/rb)
** -k  => reverse rotate k times (rra/rrb)
*/
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

/*
** perform combined rotations on both stacks first
** then finish remaining
*/
void	perform(t_stack *a, t_stack *b, int ca, int cb)
{
	while (ca > 0 && cb > 0) //rotate both up
	{
		op_rr(a, b);
		ca--;
		cb--;
	}
	while (ca < 0 && cb < 0) //rotate both down
	{
		op_rrr(a, b);
		ca++;
		cb++;
	}
	while (ca-- > 0)
		op_ra(a);
	while (ca++ < 0)
		op_rra(a);
	while (cb-- > 0)
		op_rb(b);
	while (cb++ < 0)
		op_rrb(b);
}
