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

char	*join_free(char *s1, char *s2)
{
	char	*temp_buffer;

	temp_buffer = f_strjoin(s1, s2);
	free(s1);
	return (temp_buffer);
}
