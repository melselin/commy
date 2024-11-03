/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:46:49 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 13:30:06 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t  i = 0;
    if (size == 0)
        return ft_strlen(src);

    while (i < size - 1 && src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }

    dst[i] = '\0';

    return ft_strlen(src);
}