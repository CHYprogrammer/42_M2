/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:44:10 by heychong          #+#    #+#             */
/*   Updated: 2026/02/09 00:00:51 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_list **lst)
{
	t_list	*current;
	t_list	*next_tmp;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next_tmp = current->next;
		free(current);
		current = next_tmp;
	}
	*lst = NULL;
}

int	free_stack(t_stack *stack)
{
	free_lst(&stack->a_top);
	free_lst(&stack->b_top);
	stack->size_a = 0;
	stack->size_b = 0;
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_list	*cur;

	if (!stack || !stack->a_top)
		return (1);
	cur = stack->a_top;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	put_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (0);
	stack.a_top = NULL;
	stack.b_top = NULL;
	stack.size_a = 0;
	stack.size_b = 0;
	if (!init_stack_a(&stack, argc, argv) || !set_order_and_check_dup(&stack))
	{
		free_stack(&stack);
		return (put_error());
	}
	if (is_sorted(&stack))
		return (free_stack(&stack));
	if (stack.size_a <= 5)
		sort_short(&stack);
	else
		radix_sort(&stack);
	free_stack(&stack);
	return (0);
}
