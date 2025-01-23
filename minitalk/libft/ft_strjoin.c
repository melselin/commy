/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:42 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/04 13:33:47 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = (char *)malloc(len1 + len2 + 1);
	if (!joined_str)
		return (NULL);
	i = -1;
	while (++i < len1)
		joined_str[i] = s1[i];
	while (i - len1 < len2)
	{
		joined_str[i] = s2[i - len1];
		i++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}
