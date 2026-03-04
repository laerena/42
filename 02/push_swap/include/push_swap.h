/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:48:47 by leilai            #+#    #+#             */
/*   Updated: 2026/03/04 16:31:45 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

// data structures
// one element of the stack: one number + link to the next
typedef struct s_node
{
	int				value;
	int				index;//index of the value in the sorted order 
	struct s_node	*next;//arrow to next node
}	t_node;

// a stack: pointer to the top + its size
typedef struct s_stack
{
	t_node	*top;// pointer to first node(top of stack)
	int		size;// number of elements
}	t_stack;

// parsing
t_stack	*parse_stack_a(int ac, char **av);

// error handling
void	error_exit(void);

// stack primitives
t_stack	*stack_init(void);
t_node	*node_new(int value);
void	stack_push_top(t_stack *stack, t_node *new_node);
void	stack_push_bottom(t_stack *stack, t_node *new_node);
t_node	*stack_pop_top(t_stack *stack);
t_node	*stack_pop_bottom(t_stack *stack);
void	stack_clear(t_stack *stack);

// operations
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);

void	op_sa(t_stack *a);
void	op_sb(t_stack *b);
void	op_ss(t_stack *a, t_stack *b);

void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rr(t_stack *a, t_stack *b);

void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);

// helpers
char	**ft_split(char const *s, char c);
void	free_tokens(char **tokens);
int		is_sorted(t_stack *a);

// sorting
void	normalize_stack(t_stack *a);
void	sort_3(t_stack *a);
void	pos_to_top(
			t_stack *stack,
			int pos,
			void (*rotate)(t_stack *),
			void (*rev_rotate)(t_stack *)
			);
void	small_sort(t_stack *a, t_stack *b);
void	chunk_sort(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

#endif
