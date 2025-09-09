/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:40:34 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/07 17:15:02 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_buffer(char *buffer, int fd)
{
	char	*temp_buffer;
	ssize_t	bytes_read;

	if (!buffer)
		buffer = f_calloc(1, 1);
	if (!buffer)
		return (NULL);
	temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(temp_buffer), NULL);
		temp_buffer[bytes_read] = '\0';
		buffer = join_free(buffer, temp_buffer);
		if (!buffer)
			return (free(temp_buffer), NULL);
		if (f_strchr(temp_buffer, '\n'))
			break ;
	}
	return (free(temp_buffer), buffer);
}

char	*fill_line(char *buffer)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = f_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = buffer[i];
	return (line);
}

char	*update_buffer(char *buffer, char *line)
{
	char	*new_buffer;
	size_t	buffer_len;
	size_t	line_len;
	size_t	i;

	buffer_len = f_strlen(buffer);
	line_len = f_strlen(line);
	if (line_len == buffer_len)
		return (free(buffer), NULL);
	new_buffer = f_calloc(buffer_len - line_len + 1, sizeof(char));
	if (!new_buffer)
		return (free(buffer), NULL);
	i = -1;
	while (buffer[line_len + ++i])
		new_buffer[i] = buffer[line_len + i];
	return (free(buffer), new_buffer);
}

char	*get_next_line(int fd, char **buffer)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
		return (NULL);
	*buffer = fill_buffer(*buffer, fd);
	if (!*buffer)
		return (NULL);
	line = fill_line(*buffer);
	*buffer = update_buffer(*buffer, line);
	if (!line || line[0] == '\0')
	{
		if (*buffer)
		{
			free(*buffer);
			*buffer = NULL;
		}
		return (free(line), NULL);
	}
	return (line);
}

void	free_all_gnl_buffers(void)
{
	static char	*buffers[MAX_FD] = {0};
	int			i;

	i = 0;
	while (i < MAX_FD)
	{
		if (buffers[i])
		{
			free(buffers[i]);
			buffers[i] = NULL;
		}
		i++;
	}
}
