/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:15:24 by heychong          #+#    #+#             */
/*   Updated: 2026/02/09 01:30:25 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	size_t	len;
	char	*word;
	size_t	i;

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

char	**exec_split(char *str, char delimiter, char **result)
{
	size_t	i;

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

char	**ft_split(char *str, char delimiter)
{
	char	**result;
	int		words;

	words = count_words(str, delimiter);
	if (words == 0)
		return (0);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	return (exec_split(str, delimiter, result));
}
