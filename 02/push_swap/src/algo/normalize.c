/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:37:12 by leilai            #+#    #+#             */
/*   Updated: 2026/03/06 16:37:13 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// copy stack values into an array
static int	*stack_to_array(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;

	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	cur = a->top;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	return (arr);
}

/* 
** sort the array in ascending order
** simple O(n^2) bubble sort, as n is small (n<=500)
*/
static void	sort_array(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

// helper function to find the position of 'value' in the sorted array

static int	find_index(int *sorted, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);//should never happen if parse is correct
}

/*
** assign to each node in stack a its index in the sorted order
** for each node: 
** find index of node->value in the sorted array
** store it into node->index
*/

static void	apply_normalization(t_stack *a, int *sorted, int n)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		cur->index = find_index(sorted, n, cur->value);
		if (cur->index == -1)
			error_exit();
		cur = cur->next;
	}
}

void	normalize_stack(t_stack *a)
{
	int		*arr;

	if (!a || a->size < 2)
		return ;
	arr = stack_to_array(a);
	if (!arr)
		error_exit();
	sort_array(arr, a->size);
	apply_normalization(a, arr, a->size);
	free(arr);
}
