/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:19:24 by heychong          #+#    #+#             */
/*   Updated: 2026/01/31 18:40:21 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stsdlib.h>

typedef struct	s_list
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

static int is_valid_number_str(const char *str);
static int	ft_atoi(const char *str);
int	free_split(char	**split);
int	init_stack_a(t_stack *stack, int argc, char **argv);
int	detect_duplicates(t_list *stack);
void	radix_sort(t_stack *stack);
void	push_swap_bit(t_stack *stack, int bit_pos, int *a_count);

#endif
