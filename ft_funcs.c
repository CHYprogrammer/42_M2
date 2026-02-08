/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:15:24 by heychong          #+#    #+#             */
/*   Updated: 2026/02/08 19:50:34 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_atol
long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	if (!str)
		return (0);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (res > (LONG_MAX / 10) || res < (LONG_MIN / 10))
			return (LONG_MAX);
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}

//ft_split
int	count_words(char const *str, char delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != delimiter && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*str == delimiter)
			in_word = 0;
		str++;
	}
	return (count);
}

char	*dup_word(char const *str, char delimiter)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (str[len] && str[len] != delimiter)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**free_all(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
	return (NULL);
}

char	**ft_split(char *str, char delimiter)
{
	char	**result;
	int		i;

	if (!str)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(str, delimiter) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != delimiter)
		{
			result[i] = dup_word(str, delimiter);
			if (!result[i])
				return (free_all(result, i));
			i++;
			while (*str && *str != delimiter)
				str++;
		}
		else
			str++;
	}
	result[i] = NULL;
	return (result);
}
