/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:57:40 by heychong          #+#    #+#             */
/*   Updated: 2026/02/06 14:03:34 by heychong         ###   ########.fr       */
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

void	ra(t_stack *stack)
{
	t_list	*first;
	t_list	*last;

	if (stack->size_a < 2)
		return ;
	first = stack->a_top;
	last = stack->a_top;
	while (last->next)
		last = last->next;
	stack->a_top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rra(t_stack *stack)
{
	t_list	*last;
	t_list	*prev_to_last;

	if (stack->size_a < 2)
		return ;
	prev_to_last = stack->a_top;
	while (prev_to_last->next->next)
		prev_to_last = prev_to_last->next;
	last = prev_to_last->next;
	prev_to_last->next = NULL;
	last->next = stack->a_top;
	stack->a_top = last;
	write(1, "rra\n", 4);
}
