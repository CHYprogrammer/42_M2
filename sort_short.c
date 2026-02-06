/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:16:02 by heychong          #+#    #+#             */
/*   Updated: 2026/02/06 18:01:10 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_list *a_top)
{
	int		pos;
	int		min_pos;
	int		min_val;
	t_list	*cur;

	if (!a_top)
		return (0);
	pos = 0;
	min_pos = 0;
	min_val = a_top->value;
	cur = a_top;
	while (cur)
	{
		if (cur->value < min_val)
		{
			min_val = cur->value;
			min_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (min_pos);
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (stack->size_a < 3)
		return ;
	a = stack->a_top->value;
	b = stack->a_top->next->value;
	c = stack->a_top->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

void	sort_four(t_stack *stack)
{
	int	pos;

	pos = find_min_pos(stack->a_top);
	if (pos == 1)
		ra(stack);
	else if (pos == 2)
	{
		ra(stack);
		ra(stack);
	}
	else if (pos == 3)
		rra(stack);
	pb(stack);
	sort_three(stack);
	pa(stack);
}

void	sort_five(t_stack *stack)
{
	int	pos;

	pos = find_min_pos(stack->a_top);
	if (pos == 1)
		ra(stack);
	else if (pos == 2)
	{
		ra(stack);
		ra(stack);
	}
	else if (pos == 3)
	{
		rra(stack);
		rra(stack);
	}
	else if (pos == 4)
		rra(stack);
	pb(stack);
	sort_four(stack);
	pa(stack);
}

void	sort_short(t_stack *stack)
{
	if (stack->size_a <= 1)
		return ;
	if (stack->size_a == 2)
	{
		if (stack->a_top->value > stack->a_top->next->value)
			sa(stack);
	}
	else if (stack->size_a == 3)
		sort_three(stack);
	else if (stack->size_a == 4)
		sort_four(stack);
	else if (stack->size_a == 5)
		sort_five(stack);
}
