/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:22:53 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/11/04 13:23:02 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strappend(char **s1, char *s2)
{
	char	*str;
	int		l1;
	int		l2;

	l1 = ft_strlen(*s1);
	l2 = ft_strlen(s2);
	if (!*s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s2) + ft_strlen(*s1) + 1);
	free(*s1);
	return (str);
}
