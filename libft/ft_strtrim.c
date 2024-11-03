/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:51:50 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 21:19:52 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set) {
    char    *trimmed_str;
    size_t  start, end, len;
    // Eğer s1 veya set NULL ise, NULL döndür
    if (!s1 || !set) {
        return NULL;
    }
    // Başlangıç indeksini bul
    start = 0;
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;
    end = ft_strlen(s1);   // Son indeksini bul

    while (end > start && ft_strchr(set, s1[end - 1]))
        end--;

    len = end - start;

    trimmed_str = (char *)malloc(len + 1);   // Kırpılmış string için yeterli bellek ayır
    if (!trimmed_str)
        return NULL; // Bellek ayırma hatası

    // Kopyalama işlemi
    ft_memcpy(trimmed_str, s1 + start, len); // Başlangıç indeksinden itibaren kopyala
    trimmed_str[len] = '\0'; // Null terminator ekle

    return trimmed_str; // Kırpılmış stringi döndür
}
