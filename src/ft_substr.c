/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:46:50 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/29 14:38:38 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:46:50 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/10/29 13:46:50 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char *ft_substr(char const *s, unsigned int start,size_t len) {
    char *new_str;
    size_t new_len;
    new_str = malloc(len + 1);
    if (!new_str)
        return NULL;
    new_len = 0;
    while (start < len) {
        new_len = len - start;
        memcpy(new_str + start, s, new_len);
        new_str[new_len] = '\0';
        start += new_len;
    }
    return new_str;
}