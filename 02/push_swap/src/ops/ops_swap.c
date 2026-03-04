#include "push_swap.h"

/*
** swap the first two nodes of a stack (internal helper)
** swap values to keep pointer logic safe and simple
*/
static void	swap_top_two(t_stack *s)
{
	int	tmp;

	if (!s || s->size < 2)
		return ;
	tmp = s->top->value;
	s->top->value = s->top->next->value;
	s->top->next->value = tmp;
	tmp = s->top->index;
	s->top->index = s->top->next->index;
	s->top->next->index = tmp;
}

void	op_sa(t_stack *a)
{
	swap_top_two(a);
	write(1, "sa\n", 3);
}

void	op_sb(t_stack *b)
{
	swap_top_two(b);
	write(1, "sb\n", 3);
}

void	op_ss(t_stack *a, t_stack *b)
{
	swap_top_two(a);
	swap_top_two(b);
	write(1, "ss\n", 3);
}