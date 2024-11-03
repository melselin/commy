/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:39:00 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 21:05:54 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *joined_str;
    size_t  len1, len2, i, j;

    // Eğer s1 veya s2 NULL ise, NULL döndür.
    if (!s1 || !s2)
        return NULL;

    len1 = ft_strlen(s1);  // İlk stringin uzunluğunu al
    len2 = ft_strlen(s2);  // İkinci stringin uzunluğunu al

    // Birleşim için gereken bellek alanını ayır (s1 uzunluğu + s2 uzunluğu + '\0' için +1)
    joined_str = (char *)malloc(len1 + len2 + 1);
    if (!joined_str)  // Bellek ayrımı başarısızsa NULL döndür
        return NULL;
    // İlk stringi joined_str'e kopyala
    i = 0;
    while (i < len1) {
        joined_str[i] = s1[i];
        i++;
    }
    // İkinci stringi joined_str'e ekle
    j = 0;
    while (j < len2) {
        joined_str[i + j] = s2[j];
        j++;
    }

    joined_str[i + j] = '\0';  // Null-terminator ekle

    return joined_str;
}