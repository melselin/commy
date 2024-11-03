/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:31:49 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 13:34:01 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
size_t  ft_strlcat(char *dest, const char *src, size_t size) {
    size_t  dest_len = ft_strlen(dest);
    size_t  src_len = ft_strlen(src);
    size_t  i = 0;

    if (size == 0) {
        return src_len;
    }

    if (dest_len >= size) {
        return size + src_len;
    }

    while (i < size - dest_len - 1 && src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }

    dest[dest_len + i] = '\0';

    return dest_len + src_len;
}