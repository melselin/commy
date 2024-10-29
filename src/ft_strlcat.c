/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:31:49 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/29 10:34:25 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
int ft_strlcat(char *dst, const char *src, size_t dstsize) {
    char *d = dst;
    const char *s = src;
    size_t n = dstsize;
    while (n--) {
        if ((*d++ = *s++) == '\0')
            {
            
            }
    }
}