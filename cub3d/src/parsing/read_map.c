/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:42:26 by lakkerma          #+#    #+#             */
/*   Updated: 2025/09/09 13:14:06 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

void	init_map_state(t_map_state *state, int *flag)
{
	state->in_map = 0;
	state->line_count = 0;
	state->map_flag = flag;
	state->map_start = -1;
}

int	is_map_content(char *line)
{
	if (line[0] && ft_strchr("01NSEWXD ", line[0]) && !is_element_line(line))
		return (1);
	return (0);
}

void	check_empty_line_map(t_game *game, int fd)
{
	int		temp_fd;
	int		more_map;
	char	*temp_line;
	char	*buffer;

	buffer = NULL;
	more_map = 0;
	temp_fd = dup(fd);
	temp_line = get_next_line(temp_fd, &buffer);
	while (temp_line)
	{
		if (is_map_content(temp_line))
		{
			more_map = 1;
			free(temp_line);
			break ;
		}
		free(temp_line);
		temp_line = get_next_line(temp_fd, &buffer);
	}
	close(temp_fd);
	if (buffer)
		free(buffer);
	if (more_map)
		error_exit(game, "Error: empty line in map\n");
}

void	cleanup_and_exit(t_game *game, t_read_context *ctx, char *line,
		char *error_msg)
{
	free_map_data(game);
	if (ctx->lines)
		free_lines_array(ctx->lines, ctx->line_count);
	if (ctx->buffer)
		free(ctx->buffer);
	if (line)
		free(line);
	error_exit(game, error_msg);
}

void	process_map_content(t_game *game, char *line, t_map_state *state,
		t_read_context *ctx)
{
	if (state->map_start == -1)
	{
		state->map_start = state->line_count;
		*(state->map_flag) = state->line_count;
		state->in_map = 1;
	}
	else if (!state->in_map)
	{
		cleanup_and_exit(game, ctx, NULL, "Error: map not continuous\n");
	}
	game->map_height++;
	if (ft_strlen(line) > game->map_width)
		game->map_width = ft_strlen(line);
}
