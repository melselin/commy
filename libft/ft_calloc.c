/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:15:44 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 20:32:00 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void    *ft_calloc(size_t nmemb, size_t size)
{
    size_t  total_size = nmemb * size;

    void    *ptr = malloc(total_size);
    if (ptr == NULL)
    {
        return NULL;
    }
    ft_memset(ptr, 0, total_size);

    return ptr;
}

