/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:46:50 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/03 20:53:39 by meriza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char    *ft_substr(char const *s, unsigned int start, size_t len) {
    char *substr;
    size_t  i;
    size_t  s_len;

    if (!s)  // Eğer kaynak string null ise, NULL döndür.
        return NULL;

    s_len = ft_strlen(s);  // kaynak stringin uzunluğunu bul.

    // Eğer start, s'in uzunluğunu aşıyorsa, boş bir string döndür.
    if (start >= s_len)
        return ft_strdup("");

    // Substringin uzunluğu s_len - start ile len arasında olmalı.
    if (len > s_len - start)
        len = s_len - start;

    // Substring için bellek ayır (len + 1, '\0' sonlandırıcı için)
    substr = (char *)malloc(len + 1);
    if (!substr)  // Eğer bellek ayrımı başarısızsa, NULL döndür.
        return NULL;

    // Substringi kopyala
    i = 0;
    while (i < len && s[start + i] != '\0') {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';  // Null-terminator

    return substr;
}