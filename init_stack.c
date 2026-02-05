/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:15:48 by heychong          #+#    #+#             */
/*   Updated: 2026/02/05 20:21:30 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_split(char	**split)
{
	char	**tmp;

	if (!split)
		return (0);
	tmp = split;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(split);
	return (0);
}

static int	is_valid_number_str(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	init_stack_a(t_stack *stack, int argc, char **argv)
{
	int		i;
	char	**nums;
	int		j;
	long	value;

	stack->a_top = NULL;
	stack->size_a = 0;
	i = 1;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		if (!nums)
			return (0);
		j = 0;
		while (nums[j])
		{
			if (!is_valid_number_str(nums[j]))
				return (free_split(nums));
			value = ft_atol(nums[j]);
			if (value > INT_MAX || value < INT_MIN)
				return (free_split(nums));
			ft_lstadd_back(&stack->a_top, ft_lstnew((int)value));
			stack->size_a++;
			j++;
		}
		free_split(nums);
		i++;
	}
	return (1);
}
