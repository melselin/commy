/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:01:12 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 21:58:09 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char *ft_strmapi(char const *s, char (*f)(unsigned int, char)) {
    if (!s || !f) // Eğer string veya fonksiyon NULL ise
        return NULL;

    size_t len = ft_strlen(s);
    char *result = (char *)malloc(len + 1); // Yeni string için bellek ayır
    if (!result) // Bellek ayırma hatası kontrolü
        return NULL;

    unsigned int i = 0;
    while (i < len) {
        result[i] = f(i, s[i]); // Her karaktere f fonksiyonunu uygula
        i++;
    }
    result[len] = '\0'; // Null terminatör ekle

    return result; // Yeni oluşturulan stringi döndür
}