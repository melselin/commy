/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:05:24 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/06 16:08:33 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	i;

	n_len = ft_strlen(needle);
	if (n_len == 0)
	{
		return ((char *)haystack);
	}
	i = 0;
	while (i < len)
	{
		if (haystack[i] == needle[0])
		{
			if (i + n_len <= len)
			{
				if (ft_memcmp(haystack + i, needle, n_len) == 0)
				{
					return ((char *)(haystack + i));
				}
			}
		}
		i++;
	}
	return (NULL);
}
