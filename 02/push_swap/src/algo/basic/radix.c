#include "push_swap.h"

/*
** if you have n elements, normalized indexes go from 0 to n-1
** eg. n = 5, index 0..4, max is 4, binary 100, bits = 3
*/
static int	max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = a->size - 1;
	bits = 0;
	while ((max >> bits) != 0) 
	// right shift max until it becomes 0, counting how many shifts we can do
		bits++;
	return (bits);
}

/*
** for each bit position from 0 to max_bits-1:
** - scan every element in stack a (exactly a->size times)
** - if current top has bit = 0, push to b, else, rotate a
** - after scanning all elements, push everything back from b to a
*/
void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	i;
	int	size;
	int	max;

	if (!a || a->size < 2)
		return ;
	max = max_bits(a);
	bit = 0;
	while (bit < max)
	{
		/*
		** we can process exactly size elements of A for each bit
		** because we are modifying A during the loop (rotating)
		** we need to store the original size at the start of the loop
		*/
		size = a->size;
		i = 0;
		while (i < size)
		{
			/* 
			** check the current bit of the top element's index
			** ((index >> bit) & 1) returns 0 or 1
			** if 0, push to b, else rotate a
			*/
			if (((a->top->index >> bit) & 1) == 0)
				op_pb(a, b);
			else
				op_ra(a);
			i++;
		}
		while (b->size > 0)
			op_pa(a, b);
		bit++;
	}
}
