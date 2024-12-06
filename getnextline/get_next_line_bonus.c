/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:40:34 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/12/06 13:40:59 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + (buffer[i] == '\n') + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*prepare_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(ft_strlen(buffer) - i, sizeof(char));
	if (!new_buffer)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*read_to_buffer(int fd, char *buffer)
{
	char	*temp;
	int		bytes_read;

	temp = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (!buffer)
		{
			free(temp);
			return (NULL);
		}
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffers[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	buffers[fd] = read_to_buffer(fd, buffers[fd]);
	if (!buffers[fd])
		return (NULL);
	line = extract_line(buffers[fd]);
	buffers[fd] = prepare_buffer(buffers[fd]);
	return (line);
}
