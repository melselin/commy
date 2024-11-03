/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:02:39 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 16:20:09 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:02:39 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/29 11:02:39 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void	*ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *ptr = s;
    unsigned char value = (unsigned char)c;

    while (n--) {
        if (*ptr == value) {
            return (void *)ptr;
        }
        ptr++;
    }
    return NULL;
}
