/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:57:40 by heychong          #+#    #+#             */
/*   Updated: 2026/02/05 18:58:29 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
