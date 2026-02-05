/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:20:22 by heychong          #+#    #+#             */
/*   Updated: 2026/02/05 20:23:03 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	my_qsort(int *arr, int first, int last)
{
	int	pivot;
	int	i;
	int	j;

	if (first >= last)
		return ;
	i = first;
	j = last;
	pivot = arr[(first + last) / 2];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
			swap_int(&arr[i++], &arr[j--]);
	}
	if (first < j)
		my_qsort(arr, first, j);
	if (i < last)
		my_qsort(arr, i, last);
}
