/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:49:15 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/29 10:55:24 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
char *ft_strchr(const char *s, int c) {
    if(s == NULL) {
        return  NULL;
    }
    const char *p = s;
    while (*p != '\0') {
        if (*p == c)
            return (char *)p;
    }
    return (char *)s;
}