/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:08:57 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 16:44:31 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  i = 0;
    size_t  j;

    if (*needle == '\0') {
        return (char *)haystack;
    }

    while (haystack[i] != '\0' && i < len) {
        j = 0;
        while (haystack[i + j] == needle[j] && (i + j) < len) {
            if (needle[j + 1] == '\0') {
                return (char *)&haystack[i];
            }
            j++;
        }
        i++;
    }

    return NULL;
}