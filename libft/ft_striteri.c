/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:01:56 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 22:00:14 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void ft_striteri(char *s, void (*f)(unsigned int, char*)) {
    if (!s || !f) // Eğer string veya fonksiyon NULL ise
        return;

    unsigned int i = 0; // İndeks değişkeni
    while (s[i] != '\0') { // Stringin sonuna kadar git
        f(i, &s[i]); // İndeksi ve karakterin adresini fonksiyona gönder
        i++; // İndeksi artır
    }
}