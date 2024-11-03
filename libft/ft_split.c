/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:58:51 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 22:12:58 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
static int count_words(const char *s, char c) {
    int count = 0;
    int in_word = 0;

    while (*s) {
        if (*s != c && !in_word) {
            in_word = 1; // Yeni bir kelimeye başlıyoruz
            count++;
        } else if (*s == c) {
            in_word = 0; // Kelimenin sonuna geldik
        }
        s++;
    }
    return count;
}

static char *get_word(const char *s, char c) {
    size_t len = 0;
    while (s[len] && s[len] != c) {
        len++;
    }
    char *word = (char *)malloc(len + 1);
    if (word) {
        strncpy(word, s, len);
        word[len] = '\0'; // Null terminator ekle
    }
    return word;
}

char **ft_split(char const *s, char c) {
    if (!s) return NULL;

    int word_count = count_words(s, c);
    char **result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (!result) return NULL; // Bellek ayırma hatası

    int i = 0;
    while (*s) {
        if (*s != c) {
            result[i] = get_word(s, c);
            if (!result[i]) {
                while (i > 0) { // Önceki allocated kelimeleri serbest bırak
                    free(result[--i]);
                }
                free(result); // Diziyi serbest bırak
                return NULL;
            }
            i++;
            while (*s && *s != c)
                s++; // Kelimeyi geç
            s++; // Ayırıcıyı geç
    }
    result[i] = NULL; // Dizinin sonuna NULL ekle
    return result;
}