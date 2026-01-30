/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:41:14 by heychong          #+#    #+#             */
/*   Updated: 2026/01/30 19:55:20 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stack)
{
	int	bit_pos;
	int	total_bits;
	int	size;
	int	a_count;

	total_bits = 31; //intは32bit、符号考慮で31bit
	size = stack->size_a;
	bit_pos = 0;
	while (bit_pos < total_bits)
	{
		a_count = 0;
		//bit_pos番目のビットをチェックして振り分け
		push_swap_bit(stack, bit_pos, &a_count);
		//Aにすべて戻す（逆順で安定ソート）
		while (stack->size_b > 0)
			pa(stack);
		bit_pos++;
	}
}

void	push_swap_bit(t_stack *stack, int bit_pos, int *a_count)
{
	t_list	*current;
	int		bit;

	current = stack->a_top;
	while (current)
	{
		bit = (current->value >> bit_pos) & 1;
		if (bit == 0)
		{
			*(a_count)++;
			ra(stack); //0側をAに残す（回転で位置調整）
		}
		else
			pb(stack); //1側をBに移動
		current = stack->a_top; //回転後の新トップ
	}
}
