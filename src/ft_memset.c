/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:44:23 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/24 11:58:01 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

int ft_memset(void *p, int c, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        ((unsigned char *)p)[i] = c;
    }
    return 0;
}
int main(void) {
    unsigned char *p = (unsigned char *)0x12345678;
    printf("%p\n", p);
    printf("%p\n", &p);
    return (0);
}
