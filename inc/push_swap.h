/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:19:24 by heychong          #+#    #+#             */
/*   Updated: 2026/02/02 18:22:18 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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

#endif
