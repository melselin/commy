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
/*#include "libft.h"

static int	count_words(const char *s, char c)
{
    int	count = 0;
    int	in_word = 0;

    while (*s)
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

// Yardımcı fonksiyon: belirli uzunluktaki bir kelimeyi kopyalar.
static char	*copy_word(const char *start, int len)
{
    char	*word;

    word = (char *)malloc((len + 1) * sizeof(char));
    if (!word)
        return (NULL);
    for (int i = 0; i < len; i++)
        word[i] = start[i];
    word[len] = '\0';
    return (word);
}

// ft_split fonksiyonu: verilen stringi belirli bir ayırıcıya göre böler.
char	**ft_split(char const *s, char c)
{
    if (!s)
        return (NULL);
    int	words = count_words(s, c);
    char	**result = (char **)malloc((words + 1) * sizeof(char *));
    if (!result)
        return (NULL);
    int	i = 0;
    while (*s)
    {
        if (*s != c)
        {
            const char	*word_start = s;
            int	word_len = 0;
            while (*s && *s != c)
            {
                word_len++;
                s++;
            }
            result[i] = copy_word(word_start, word_len);
            if (!result[i++])
            {
                // Hata durumunda, bellekteki yerleri serbest bırak.
                while (i > 0)
                    free(result[--i]);
                free(result);
                return (NULL);
            }
        }
        else
            s++;
    }
    result[i] = NULL; // Dizinin sonuna NULL ekleyin.
    return (result);
}*/
