/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:40:08 by heychong          #+#    #+#             */
/*   Updated: 2026/01/22 18:27:20 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->size_a < 2)
		return ;
	first = stack->a_top;
	second = first->next;
	first->next = second->next;
	if (second -> next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	first->prev = NULL;

	stack->a_top = second;
	write(1, "sa\n", 3);
}