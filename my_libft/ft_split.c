/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:08:46 by amacarul          #+#    #+#             */
/*   Updated: 2024/09/21 18:14:12 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count ++;
		}
		else if (*s == c)
			in_word = 0;
		s ++;
	}
	return (count);
}

static int	next_word(const char *s, char c, int i, int mode)
{
	if (mode == 0)
	{
		while (s[i] == c)
			i ++;
	}
	else
	{
		while (s[i] && s[i] != c)
			i ++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int end)
{
	char	*duplicated;
	int		pos;

	pos = 0;
	duplicated = (char *)malloc ((end - start + 1) * sizeof(char));
	if (duplicated == NULL)
		return (NULL);
	while (start < end)
	{
		duplicated[pos] = str[start];
		pos ++;
		start ++;
	}
	duplicated[pos] = '\0';
	return (duplicated);
}

static char	**process_words(char const *s, char c, char **array)
{
	int	pos[2];
	int	word_index;

	pos[0] = 0;
	word_index = 0;
	while (s[pos[0]])
	{
		pos[1] = next_word(s, c, pos[0], 0);
		pos[0] = next_word(s, c, pos[1], 1);
		if (pos[1] < pos[0])
		{
			array[word_index] = word_dup(s, pos[1], pos[0]);
			if (array[word_index] == NULL)
			{
				while (word_index > 0)
					free(array[--word_index]);
				free(array);
				return (NULL);
			}
			word_index ++;
		}
	}
	array[word_index] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	array = (char **)ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (array == NULL)
		return (NULL);
	array = process_words(s, c, array);
	return (array);
}
