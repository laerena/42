/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:34:46 by leilai            #+#    #+#             */
/*   Updated: 2026/03/04 18:47:18 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** free all nodes in the stack, then free the stack itself
*/
void	stack_clear(t_stack *stack)
{
	t_node	*cur;
	t_node	*next;

	if (!stack)
		return ;
	cur = stack->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(stack);
}

/*
** . used when you have the actual struct 
*** (access a field inside a struct value)
** -> used when you have a pointer to a struct 
*** (follow the pointer to the struct, then access its field)
*/

/*
** allocate and initialize an empty stack

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

** create a new node containing "value"

t_node	*node_new(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

** push a node on top of the stack
** (new node becomes the new top)

void	stack_push_top(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

** push a node at the bottom of the stack
** (new node becomes the new)

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

** remove and return the node at the top of the stack
** (returns NULL if stack is empty)

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

** remove and return the node at the bottom of the stack

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
*/
