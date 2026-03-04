#include "push_swap.h"

/*
** push a node on top of the stack
** (new node becomes the new top)
*/
void	stack_push_top(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

/*
** push a node at the bottom of the stack
** (new node becomes the new)
*/
void	stack_push_bottom(t_stack *stack, t_node *new_node)
{
	t_node	*cur;

	if (!stack || !new_node)
		return ;
	new_node->next = NULL; //give new_node a NULL for new_node.next
	if (!stack->top) //if no first node
		stack->top = new_node;
	else
	{
		cur = stack->top;
		while (cur->next)
			cur = cur->next;
		cur->next = new_node;
	}
	stack->size++;
}