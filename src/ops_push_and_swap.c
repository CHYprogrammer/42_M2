/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_and_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:40:08 by heychong          #+#    #+#             */
/*   Updated: 2026/02/02 13:46:30 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (stack->size_a < 2)
		return ;
	first = stack->a_top;
	second = first->next;
	third = second->next;
	stack->a_top = second;
	second->next = first;
	first->next = third;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (stack->size_b < 2)
		return ;
	first = stack->b_top;
	second = first->next;
	third = second->next;
	stack->b_top = second;
	second->next = first;
	first->next = third;
	write(1, "sb\n", 3);
}

void	pa(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size_b == 0)
		return ;
	tmp = stack->b_top;
	stack->b_top = tmp->next;
	tmp->next = stack->a_top;
	stack->a_top = tmp;
	stack->size_a++;
	stack->size_b--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size_a == 0)
		return ;
	tmp = stack->a_top;
	stack->a_top = tmp->next;
	tmp->next = stack->b_top;
	stack->b_top = tmp;
	stack->size_b++;
	stack->size_a--;
	write(1, "pb\n", 3);
}