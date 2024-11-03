/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:27:10 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 22:07:42 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void ft_putnbr_fd(int n, int fd) {
    if (n < 0) {
        write(fd, "-", 1); // Negatif sayılarda '-' işareti yaz
        n = -n; // Sayıyı pozitif yap
    }

    if (n >= 10) { // 10'dan büyükse
        ft_putnbr_fd(n / 10, fd); // Rekürsif olarak ondalık basamağı yaz
    }

    // Son basamağı yaz
    char c = (n % 10) + '0'; // Son basamağı karaktere dönüştür
    write(fd, &c, 1); // Son basamağı yaz
}