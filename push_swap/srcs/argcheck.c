/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:24:05 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/20 16:24:45 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**split_string(char *str, char separator)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words_in_string(str, separator);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (vector_strings == NULL)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (i == 0)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (vector_strings[i] == NULL)
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word_in_string(str, separator);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}

int	count_words_in_string(char *str, char separator)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == separator)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != separator)
			i++;
	}
	return (count);
}

char	*get_next_word_in_string(char *str, char separator)
{
	static int	cursor;
	char		*word;
	int			start;
	int			len;

	len = 0;
	while (str[cursor] == separator)
		cursor++;
	start = cursor;
	while (str[cursor] && str[cursor] != separator)
	{
		cursor++;
		len++;
	}
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	len = 0;
	while (str[start] && str[start] != separator)
		word[len++] = str[start++];
	word[len] = '\0';
	return (word);
}

int	is_num(char *str_nbr)
{
	if (!(*str_nbr == '+' || *str_nbr == '-' || (*str_nbr >= '0'
				&& *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-') && !(str_nbr[1] >= '0'
			&& str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

int	is_duplicate(t_list *stack_a, int nbr)
{
	if (stack_a == NULL)
		return (0);
	while (stack_a)
	{
		if (stack_a->value == nbr)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
