/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_revrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:37:35 by leilai            #+#    #+#             */
/*   Updated: 2026/03/06 16:37:36 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** internal primitive: reverse rotate one stack
** bottom node becomes the top node
*/
static void	rev_rotate_stack(t_stack *s)
{
	t_node	*node;

	node = NULL;
	if (!s || s->size < 2)
		return ;
	node = stack_pop_bottom(s);
	stack_push_top(s, node);
}

void	op_rra(t_stack *a)
{
	rev_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	op_rrb(t_stack *b)
{
	rev_rotate_stack(b);
	write(1, "rrb\n", 4);
}

void	op_rrr(t_stack *a, t_stack *b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	write(1, "rrr\n", 4);
}