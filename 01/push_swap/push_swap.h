/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:48:47 by leilai            #+#    #+#             */
/*   Updated: 2026/01/17 10:16:33 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdlib.h>

/*
** one element of the stack: one number + link to the next
*/
typedef struct  s_node
{
    int value;
    struct s_node   *next;
}   t_node;

/*
** a stack: pointer to the top + its size
*/
typedef struct  s_stack
{
    t_node *top;
    int size;
}   t_stack;

t_stack *stack_init();
t_node  *node_new(int value);
void    stack_push_top