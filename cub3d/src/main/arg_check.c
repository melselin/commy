/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:29:15 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:29:17 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

static bool	has_cub_extension(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	if (len < 5)
		return (false);
	if (base[len - 4] == '.' && base[len - 3] == 'c' && base[len - 2] == 'u'
		&& base[len - 1] == 'b')
		return (true);
	return (false);
}

static bool	is_valid_name_chars(char *base, int len)
{
	int	i;

	i = 0;
	while (i < len - 4)
	{
		if (!((base[i] >= 'a' && base[i] <= 'z') || (base[i] >= 'A'
					&& base[i] <= 'Z') || (base[i] >= '0' && base[i] <= '9')
				|| base[i] == '_' || base[i] == '-'))
			return (false);
		i++;
	}
	return (true);
}

bool	arg_check(char *filename)
{
	char	*base;
	char	*last_slash;
	int		len;
	int		fd;

	if (!filename)
		return (false);
	last_slash = ft_strrchr(filename, '/');
	if (last_slash)
		base = last_slash + 1;
	else
		base = filename;
	len = ft_strlen(base);
	if (!has_cub_extension(base))
		return (false);
	if (!is_valid_name_chars(base, len))
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}
