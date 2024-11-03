/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:07:09 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 12:05:02 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void    *ft_memmove(void *dest, const void *src, size_t n)
{
unsigned char   *d = dest;
const unsigned char *s = src;

if (d < s) {
    size_t  i = 0;
    while (i < n) {
        d[i] = s[i];
        i++;
    }
} else {
    size_t i = n;
    while (i > 0) {
        d[i - 1] = s[i - 1];
        i--;
    }
}

return dest;
}