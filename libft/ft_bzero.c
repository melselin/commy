/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:01:26 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 11:32:44 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void    ft_bzero(void *s, size_t n)
{
    unsigned char   *p = s;
    size_t  i = 0;

    while (i < n)
    {
        p[i] = 0;
        i++;
    }
}
