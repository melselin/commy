/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:42:19 by mwelfrin          #+#    #+#             */
/*   Updated: 2024/12/06 13:42:30 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# define MAX_FD 1024

char	*get_next_line(int fd);
char	*extract_line(char *buffer);
char	*prepare_buffer(char *buffer);
char	*read_to_buffer(int fd, char *buffer);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);

#endif
