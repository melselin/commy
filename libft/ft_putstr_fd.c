/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:25:23 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 22:03:00 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void ft_putstr_fd(char *s, int fd) {
    if (s == NULL) // NULL kontrolü
        return;

    while (*s) { // Stringin sonuna kadar git
        write(fd, s, 1); // Her bir karakteri yaz
        s++; // Sonraki karaktere geç
    }
}