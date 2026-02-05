/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:16:51 by heychong          #+#    #+#             */
/*   Updated: 2026/02/05 20:09:08 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->order = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new_lst)
{
	if (!lst || !new_lst)
		return ;
	new_lst->next = *lst;
	*lst = new_lst;
}

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*last;

	if (!lst || !new_lst)
		return ;
	if (!*lst)
	{
		*lst = new_lst;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new_lst;
}
