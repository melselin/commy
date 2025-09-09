/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:11:52 by lakkerma          #+#    #+#             */
/*   Updated: 2025/09/09 13:04:56 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

static int	open_map_file(t_game *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		error_exit(game, "Error: could not open map file\n");
	}
	return (fd);
}

static void	init_doors(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'D')
			{
				game->doors[i].x = x;
				game->doors[i].y = y;
				game->doors[i].open = false;
				game->doors[i].open_progress = 0.0;
				game->doors[i].is_opening = 0;
				game->doors[i].is_closing = 0;
				i++;
			}
			x++;
		}
		y++;
	}
}

static void	init_map_counters(t_game *game)
{
	game->no.flag = 0;
	game->so.flag = 0;
	game->we.flag = 0;
	game->ea.flag = 0;
	game->floor.flag = 0;
	game->ceiling.flag = 0;
	game->total_sprites = 0;
	game->door_count = 0;
}

void	parse_map_file(t_game *game, char *file, t_parse_result *result)
{
	int	fd;

	init_map_counters(game);
	fd = open_map_file(game, file);
	result->lines = read_map(game, fd, &result->line_count, &result->map_flag);
	close(fd);
	if (!(result->lines))
	{
		free_map_data(game);
		error_exit(game, "Error: map malloc failed\n");
	}
	if (result->line_count == 0)
	{
		free_map_data(game);
		error_exit(game, "Error: map is empty\n");
	}
}

void	process_map_data(t_game *game, char **lines, int line_count,
		int map_flag)
{
	validate_player_count(game, lines, line_count, map_flag);
	allocate_map_memory(game);
	bonus_mem_sprite(game);
	bonus_mem_doors(game);
	process_text_col(game, lines, line_count, map_flag);
	process_map(game, lines, line_count, map_flag);
	bonus_load_text(game);
	free_lines_array(lines, line_count);
	validate_map(game);
	init_doors(game);
}
