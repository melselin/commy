/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:07:09 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/29 08:45:55 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memmove(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    if (dest > src) {
        while (n--) {
            *d++ = *s++;
        }
    } else {
        while (n--) {
            *d++ = *s++;
        }
    }
}