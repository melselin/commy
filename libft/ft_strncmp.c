/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:59:19 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 14:07:47 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    while (n > 0)
    {
        if (*s1 != *s2)
        {
            return ((unsigned char)*s1 - (unsigned char)*s2);
        }
        if (*s1 == '\0')
        {
            return 0;
        }
        s1++;
        s2++;
        n--;
    }
    return 0;
}