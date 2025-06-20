/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:41:22 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/12/06 13:41:49 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*f_strchr(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	f_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*f_memset(void *ptr, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (n--)
		p[n] = (unsigned char)c;
	return (ptr);
}

void	*f_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_bytes;

	total_bytes = nmemb * size;
	if (size && (total_bytes / size) != nmemb)
		return (NULL);
	ptr = (void *)malloc(total_bytes);
	if (!ptr)
		return (NULL);
	f_memset(ptr, 0, total_bytes);
	return (ptr);
}

char	*f_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = f_strlen(s1);
	s2_len = f_strlen(s2);
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}
