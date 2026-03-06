/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:37:04 by leilai            #+#    #+#             */
/*   Updated: 2026/03/06 16:37:05 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_H
# define TURK_H

# include "push_swap.h"

typedef struct s_move
{
	int	ca;
	int	cb;
	int	total;
}	t_move;

//int		chunk_size(int n);
int		target_pos(t_stack *a, int idx);
int		rot_cost(int size, int pos);
int		total_cost(int ca, int cb);
void	perform(t_stack *a, t_stack *b, int ca, int cb);
void	turk_step(t_stack *a, t_stack *b);

#endif
