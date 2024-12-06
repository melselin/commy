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
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s)
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
		}
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		len1;
	int		len2;

	len1 = 0;
	len2 = ft_strlen(s2);
	if (s1)
		len1 = ft_strlen(s1);
	result = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (s1)
	{
		ft_memcpy(result, s1, len1);
		free(s1);
	}
	ft_memcpy(result + len1, s2, len2 + 1);
	return (result);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
