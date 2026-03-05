#include "push_swap.h"
#include "turk.h"

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
/*
static void	push_to_b(t_stack *a, t_stack *b)
{
	int	chunk;
	int	limit;
	int	pushed;

	chunk = chunk_size(a->size);
	limit = chunk - 1;
	pushed = 0;

	while (a->size > 3)
	{
		if (a->top->index <= limit)
		{
			op_pb(a, b);
			pushed++;

			// same "bury smaller half" trick from chunk
			if (b->top->index <= limit - (chunk / 2))
				op_rb(b);

			if (pushed % chunk == 0)
				limit += chunk;
		}
		else
			op_ra(a);
	}
}
*/

// redusing later cost by so smaller values are pushed first (bottom half of B)
static void	push_to_b(t_stack *a, t_stack *b)
{
	int	median;

	median = a->size / 2;
	while (a->size > 3)
	{
		if (a->top->index <= median)
		{
			op_pb(a, b);
			op_rb(b);
		}
		else
			op_pb(a, b);
	}
}


/*
** perform combined rotations on both stacks first
** then finish remaining
*/
static void	rot_a(t_stack *a, int ca)
{
	while (ca > 0)
	{
		op_ra(a);
		ca--;
	}
	while (ca < 0)
	{
		op_rra(a);
		ca++;
	}
}

static void	rot_b(t_stack *b, int cb)
{
	while (cb > 0)
	{
		op_rb(b);
		cb--;
	}
	while (cb < 0)
	{
		op_rrb(b);
		cb++;
	}
}

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
	rot_a(a, ca);
	rot_b(b, cb);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	int	pos;

	push_to_b(a, b);
	sort_3(a);
	/*
	** repeatedly insert best element from B back into A
	** turk_step() will:
	**	evaluate each node in B
	**	compute cost to insert it
	**	choose cheapest
	**	rotate and pa
	*/
	while (b->size > 0)
		turk_step(a, b);
	pos = pos_min(a);
	pos_to_top(a, pos, op_ra, op_rra);
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