/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:26:26 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 22:06:29 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void ft_putendl_fd(char *s, int fd) {
    if (s == NULL) // NULL kontrolü
        return;

    while (*s) {
        write(fd, s, 1);
        s++;
    }

    write(fd, "\n", 1); // Yeni satır karakterini yaz
}