/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:42:26 by lakkerma          #+#    #+#             */
/*   Updated: 2025/09/09 13:20:17 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

void	check_elements_after_map(t_game *game, char *line, t_map_state *state,
		t_read_context *ctx)
{
	if (state->in_map && line[0] && line[0] != '\n')
	{
		if (ft_strchr("NOSEWFCDR", line[0]))
		{
			cleanup_and_exit(game, ctx, line, "Error: elements after map\n");
		}
	}
}

void	process_line_full(t_game *game, char *line, t_map_state *state,
		t_read_context *ctx)
{
	if (is_map_content(line) && !is_element_line(line))
	{
		process_map_content(game, line, state, ctx);
	}
	else
	{
		check_elements_after_map(game, line, state, ctx);
	}
	if (state->in_map && (line[0] == '\n' || line[0] == '\0'))
		check_empty_line_map(game, ctx->fd);
	bonus_count_store_sprites(game, line);
	bonus_count_doors(game, line);
}

void	process_map_lines(t_line_processor *processor)
{
	char	*line;

	while (1)
	{
		line = get_next_line(processor->fd, &processor->ctx->buffer);
		if (!line)
			break ;
		if (*(processor->line_count) >= MAX_LINES)
		{
			free_lines_array(processor->lines, *(processor->line_count));
			if (processor->ctx->buffer)
				free(processor->ctx->buffer);
			free(line);
			error_exit(processor->game, "Error: map too large\n");
		}
		processor->lines[*(processor->line_count)] = line;
		processor->state->line_count = *(processor->line_count);
		processor->ctx->line_count = *(processor->line_count);
		process_line_full(processor->game, line, processor->state,
			processor->ctx);
		(*(processor->line_count))++;
	}
}

char	**read_map(t_game *game, int fd, int *line_count, int *map_flag)
{
	char				**lines;
	t_map_state			state;
	t_read_context		ctx;
	t_line_processor	processor;

	*line_count = 0;
	init_map_state(&state, map_flag);
	lines = malloc(sizeof(char *) * MAX_LINES);
	if (!lines)
		error_exit(game, "Error: map malloc failed\n");
	ctx.fd = fd;
	ctx.lines = lines;
	ctx.buffer = NULL;
	processor.game = game;
	processor.fd = fd;
	processor.lines = lines;
	processor.line_count = line_count;
	processor.state = &state;
	processor.ctx = &ctx;
	process_map_lines(&processor);
	return (lines);
}
