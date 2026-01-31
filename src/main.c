/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:44:10 by heychong          #+#    #+#             */
/*   Updated: 2026/01/31 19:56:41 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack stack;

	if (argc < 2)
		return (0);
	stack.a_top = NULL;
	stack.b_top = NULL;
	stack.size_a = 0;
	stack.size_b = 0;

	if (!init_stack_a(&stack, argc, argv) || !detect_duplicates(stack.a_top))
	{
		write(2, "Error\n", 6);
		free_stack(&stack);
		return (1);
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

int	free_stack(t_stack *stack)
{
	free_lst(&stack->a_top);
	free_lst(&stack->b_top);
	stack->size_a = 0;
	stack->size_b = 0;
	return (0);
}

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