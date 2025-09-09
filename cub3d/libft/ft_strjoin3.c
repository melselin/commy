/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakkerma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:26:39 by lakkerma          #+#    #+#             */
/*   Updated: 2025/07/01 11:26:40 by lakkerma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(s1, s2);
	if (!temp)
		return (NULL);
	result = ft_strjoin(temp, s3);
	free(temp);
	return (result);
}
/*
char *ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
    char *result;
    size_t len1;
    size_t len2;
    size_t len3;

    if (!s1 || !s2 || !s3)
        return (NULL);

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    len3 = ft_strlen(s3);

    result = malloc(len1 + len2 + len3 + 1);
    if (!result)
        return (NULL);

    ft_memcpy(result, s1, len1);
    ft_memcpy(result + len1, s2, len2);
    ft_memcpy(result + len1 + len2, s3, len3);
    result[len1 + len2 + len3] = '\0';

    return (result);
}*/
