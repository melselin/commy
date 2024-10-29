/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:51:50 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/29 14:57:09 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

char *ft_strtrim(char const *s1, char const *set) {
    while(*set) {
        if(*s1 == *set) {
            return (1);
        }
        set++;
    }
    return (0);

    if (set==NULL || s1==NULL || set==NULL) {
        return NULL;
    }
    size_t start = 0;
    size_t end = strlen(s1);
    while(set[start] &&  is_in_set(s1[start], set) {
        start++;
    }
}
