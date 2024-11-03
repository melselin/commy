/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:56:15 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 14:01:15 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char *ft_strrchr(const char *s, int c)
{
    const char *last_occurrence = NULL;

    while (*s)
    {
        if (*s == (char)c)
        {
            last_occurrence = s;
        }
        s++;
    }

    if (c == '\0')
    {
        return (char *)s;
    }

    return (char *)last_occurrence;
}