/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:40:22 by heychong          #+#    #+#             */
/*   Updated: 2026/01/22 15:24:57 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	swap(int a, int b)
{
	int	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

int	quick_sort(t_data values)
{
}

int	radix_sort(int *nbr)
{
	
}

void counting_sort(int arr[], int n, int max)
{
	int	*count;
	int	*output;
	int	i;

	count = (int *)calloc(max + 1, sizeof(int));
	output = (int *)malloc(sizeof(int) * n);
	if (!count || !output)
		return;

	for (i = 0; i < n; i++)
		count[arr[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];

	free(count);
	free(output);
}

int main(void)
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 8;

    counting_sort(arr, n, max);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
