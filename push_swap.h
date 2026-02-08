/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:19:24 by heychong          #+#    #+#             */
/*   Updated: 2026/02/09 00:01:08 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				order;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*a_top;
	t_list	*b_top;
	int		size_a;
	int		size_b;
}	t_stack;

int		init_stack_a(t_stack *stack, int argc, char **argv);
int		set_order_and_check_dup(t_stack *stack);
void	my_qsort(int *arr, int first, int last);
void	radix_sort(t_stack *stack);
void	sort_short(t_stack *stack);
t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **lst, t_list *new_lst);
void	ft_lstadd_back(t_list **lst, t_list *new_lst);
void	sa(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rra(t_stack *stack);
long	ft_atol(const char *str);
char	**ft_split(char *str, char delimiter);

#endif
