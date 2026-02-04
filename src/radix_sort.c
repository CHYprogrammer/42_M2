/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:41:14 by heychong          #+#    #+#             */
/*   Updated: 2026/02/04 17:10:52 by heychong         ###   ########.fr       */
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

int	is_sorted(t_stack *stack)
{
	t_list	*current;

	if (!stack || !stack->a_top)
		return (1); //空orNULLはソート済み扱い
	current = stack->a_top;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_list	*ft_lstnew(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}