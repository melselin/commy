/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:46:49 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/29 14:47:55 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	ft_strlcpy(char *dst, const char *src, size_t size) {
    size_t i;
    i = 0;
    while (src[i] != '\0' && i < size) {
        dst[i] = src[i];
    }
}