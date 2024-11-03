/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:49:15 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 13:46:14 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char    *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
        {
            return (char *)s;
        }
        s++;
    }
    if (c == '\0')
    {
        return (char *)s;
    }
    return NULL;
}