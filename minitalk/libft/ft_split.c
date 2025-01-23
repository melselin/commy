/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:58:51 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/04 13:19:26 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s != c && in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		else if (*s == c)
			in_substring = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	free_words(char **words, int i)
{
	while (i > 0)
		free(words[--i]);
	free(words);
}

static char	**split_words(const char *s, char c, char **result, int word_count)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (i < word_count)
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		result[i] = word_dup(s, start, j);
		if (!result[i])
		{
			free_words(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (split_words(s, c, result, word_count));
}
