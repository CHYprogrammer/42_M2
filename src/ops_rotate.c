/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:57:45 by heychong          #+#    #+#             */
/*   Updated: 2026/01/29 19:38:57 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_list	*first;
	t_list	*last;

	if (stack->size_a < 2)
		return ;
	first = stack->a_top;
	last = ft_lstlast(stack->a_top);
	stack->a_top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	t_list	*first;
	t_list	*last;

	if (stack->size_b < 2)
		return ;
	first = stack->b_top;
	last = ft_lstlast(stack->b_top);
	stack->b_top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
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

void	rrb(t_stack *stack)
{
	t_list	*last;
	t_list	*prev_to_last;

	if (stack->size_b < 2)
		return ;
	prev_to_last = stack->b_top;
	while (prev_to_last->next->next)
		prev_to_last = prev_to_last->next;
	last = prev_to_last->next;
	prev_to_last->next = NULL;
	last->next = stack->b_top;
	stack->b_top = last;
	write(1, "rrb\n", 4);
}