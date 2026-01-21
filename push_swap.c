/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:40:12 by heychong          #+#    #+#             */
/*   Updated: 2026/01/21 18:41:07 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct s_node {
	int				data;
	struct s_stack	*next;
} t_node;

typedef struct {
	t_node *top;
} Stack;

void	push_swap(t_stack a, t_stack b)
{
	
}
