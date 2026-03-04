#include "push_swap.h"

/*
** remove and return the node at the top of the stack
** (returns NULL if stack is empty)
*/
t_node	*stack_pop_top(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	node->next = NULL;
	stack->size--;
	return (node);
}

/*
** remove and return the node at the bottom of the stack
*/
t_node	*stack_pop_bottom(t_stack *stack)
{
	t_node	*cur;
	t_node	*pre;

	if (!stack || stack->size == 0)
		return (NULL);
	if (stack->size == 1)
		return (stack_pop_top(stack));
	cur = stack->top;
	pre = NULL;
	while (cur->next)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = NULL;
	stack->size--;
	cur->next = NULL;
	return (cur);
}