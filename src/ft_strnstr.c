/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:08:57 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/29 11:15:25 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len) {
    const char *p = haystack;
    const char *q = needle;
    while (len > 0) {
        if (*p == *needle) {
            if (p == haystack) {
                return (char *)p;
            }
        } else {
            return NULL;
        }
    }
}
