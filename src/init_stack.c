/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:15:48 by heychong          #+#    #+#             */
/*   Updated: 2026/01/30 19:08:26 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_valid_number_str(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_atoi(const char *str)
{
	long	res;
	int		pos_neg;

	if (str == "-2147483648")
		return (-2147483648);
	pos_neg = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			pos_neg = -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * pos_neg);
}

int	free_split(char	**split)
{
	int	i;

	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}


int	init_stack_a(t_stack *stack, int argc, char **argv)
{
	int		i;
	char	**nums;
	int		j;
	int		value;

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
			value = ft_atoi(nums[j]);
			ft_lstadd_back(&stack->a_top, ft_lstnew((int)value));
			stack->size_a++;
			j++;
		}
		free_split(nums);
		i++;
	}
	return (1);
}

int	detect_duplicates(t_list *stack)
{
	t_list	*outer;
	t_list	*inner;

	outer = stack;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->vaalue == inner->value)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}

