/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:40:22 by heychong          #+#    #+#             */
/*   Updated: 2026/01/21 21:37:32 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int a, int b)
{
	int	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void	count_sort(int *values)
{
	int	i;
	int	len;
	int	max;

	len = sizeof(values) / sizeof(int);
	i = 0;
	max = values[0];
	while (i < len)
	{
		if (max < values[i])
			
	}
}
			

int	quick_sort(t_data values)
{
}

int	radix_sort(int *nbr)
{
	
}
