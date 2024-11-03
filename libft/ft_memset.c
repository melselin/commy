/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:44:23 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 11:14:29 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void	*ft_memset(void *s, int c, size_t n)
{
    unsigned char	*p;
    unsigned char	value;
    size_t			i;

    p = s;
    value = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        p[i] = value;
        i++;
    }
    return (s);
}