/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:08:59 by heychong          #+#    #+#             */
/*   Updated: 2026/02/09 00:01:12 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_max_bits(t_stack *stack)
{
	int		max;
	int		bits;
	t_list	*cur;

	max = 0;
	cur = stack->a_top;
	while (cur)
	{
		if (cur->order > max)
			max = cur->order;
		cur = cur->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *stack)
{
	int	bit_pos;
	int	max_bits;
	int	size;
	int	i;
	int	ord;

	size = stack->size_a;
	max_bits = calc_max_bits(stack);
	bit_pos = 0;
	while (bit_pos < max_bits)
	{
		i = 0;
		while (i++ < size)
		{
			ord = stack->a_top->order;
			if (((ord >> bit_pos) & 1) == 0)
				pb(stack);
			else
				ra(stack);
		}
		while (stack->size_b > 0)
			pa(stack);
		bit_pos++;
	}
}
