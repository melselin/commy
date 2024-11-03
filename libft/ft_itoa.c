/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:00:06 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 21:53:25 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h> // malloc ve free için
#include <unistd.h> // write için

static int get_num_length(int n) {
    int len = 0;
    if (n <= 0) len++; // Negatif sayılar için '-' işareti
    while (n)
        n /= 10;
        len++;

    return len ? len : 1; // 0 için 1 döndür
}

char *ft_itoa(int n) {
    int len = get_num_length(n);
    char *str = (char *)malloc(len + 1); // +1 for the null terminator
    if (!str) return NULL; // Bellek ayırma hatası

    str[len] = '\0'; // Null terminator ekle
    if (n < 0) {
        str[0] = '-';
        n = -n; // Negatif sayıyı pozitif hale getir
    } else if (n == 0) {
        str[0] = '0'; // N sıfırsa, doğrudan '0' ekle
    }

    while (n) {
        str[--len] = (n % 10) + '0'; // Son basamağı ekle
        n /= 10; // Bir basamağı atla
    }

    return str; // Dönüştürülmüş stringi döndür
}