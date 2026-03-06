/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:36:52 by leilai            #+#    #+#             */
/*   Updated: 2026/03/06 16:36:53 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "turk.h"

static int	iabs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

/*
** signed rotation cost: positive for rotate, negative for reverse r
** +k  => rotate k times (ra/rb)
** -k  => reverse rotate k times (rra/rrb)
*/
int	rot_cost(int size, int pos)
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

void	turk_step(t_stack *a, t_stack *b)
{
	t_node	*cur;
	t_move	move;
	int		i;
	int		ca;
	int		cb;

	cur = b->top;
	move.total = 2147483647;
	i = 0;
	while (cur)
	{
		/*
		** Compute where this element should be inserted into A,
		** then compute cost to rotate A to that position.
		*/
		ca = rot_cost(a->size, target_pos(a, cur->index));
		cb = rot_cost(b->size, i);
		/*
		** If this candidate is cheaper than the best so far,
		** save its costs in move.
		*/
		if (total_cost(ca, cb) < move.total)
		{
			move.total = total_cost(ca, cb);
			move.ca = ca;
			move.cb = cb;
		}
		i++;
		cur = cur->next;
	}
	perform(a, b, move.ca, move.cb);
	op_pa(a, b);
}
