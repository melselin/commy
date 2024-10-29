/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:15:44 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/29 13:16:18 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

#include "libft.h"
void	*ft_calloc(size_t count, size_t size) {
    void	*ptr;
    ptr = malloc(count * size);
    if (ptr == NULL)
        return NULL;
    else
        return (ft_memset(ptr, 0, count * size));
}