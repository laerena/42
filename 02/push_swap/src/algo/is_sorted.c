/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:37:09 by leilai            #+#    #+#             */
/*   Updated: 2026/03/06 16:37:10 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** check if stack a is already sorted in ascending order
** if input is already sorted, we can skip the sorting and print nothing
** return 1 if sorted, 0 if not

** prevents algo from doing unnecessary rotations/pushes
*/
int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (a->size <= 1)
		return (1);
	cur = a->top;
	while (cur->next)
	{
		// if current value is greater than next value, it's not sorted
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
