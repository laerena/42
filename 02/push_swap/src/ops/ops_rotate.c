/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:37:39 by leilai            #+#    #+#             */
/*   Updated: 2026/03/06 16:37:40 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** internal primitive: rotate one stack
** top node becomes the bottom node
*/
static void	rotate_stack(t_stack *s)
{
	t_node	*node;

	node = NULL;
	if (!s || s->size < 2)
		return ;
	node = stack_pop_top(s);
	stack_push_bottom(s, node);
}

void	op_ra(t_stack *a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	op_rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}