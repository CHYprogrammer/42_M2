/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_order_and_check_dup.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:21:01 by heychong          #+#    #+#             */
/*   Updated: 2026/02/05 19:30:48 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_values_array(t_stack *stack, int *arr)
{
	t_list	*cur;
	int		i;

	cur = stack->a_top;
	i = 0;
	while (cur && i < stack->size_a)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
}

int	detect_duplicate_in_sorted(int *arr, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (arr[i] == arr[i - 1])
			return (1);
		i++;
	}
	return (0);
}

void	set_order_from_array(t_stack *stack, int *arr)
{
	t_list	*cur;
	int		first;
	int		last;
	int		mid;

	cur = stack->a_top;
	while (cur)
	{
		first = 0;
		last = stack->size_a - 1;
		while (first <= last)
		{
			mid = (first + last) / 2;
			if (arr[mid] == cur->value)
			{
				cur->order = mid;
				break ;
			}
			else if (arr[mid] < cur->value)
				first = mid + 1;
			else
				last = mid - 1;
		}
		cur = cur->next;
	}
}

int	set_order_and_check_dup(t_stack *stack)
{
	int	*arr;

	if (!stack || stack->size_a <= 0)
		return (1);
	arr = (int *)malloc(sizeof(int) * stack->size_a);
	if (!arr)
		return (0);
	fill_values_array(stack, arr);
	my_qsort(arr, 0, stack->size_a - 1);
	if (detect_duplicate_in_sorted(arr, stack->size_a))
	{
		free(arr);
		return (0);
	}
	set_order_from_array(stack, arr);
	free(arr);
	return (1);
}
