/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakkerma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:12:16 by lakkerma          #+#    #+#             */
/*   Updated: 2025/09/03 14:12:17 by lakkerma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

static void	process_texture_line(t_game *game, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		load_texture(game, &game->no, line + 3);
		game->no.flag++;
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		load_texture(game, &game->so, line + 3);
		game->so.flag++;
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		load_texture(game, &game->we, line + 3);
		game->we.flag++;
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		load_texture(game, &game->ea, line + 3);
		game->ea.flag++;
	}
	else if (line[0] == 'D' && line[1] == 'R')
	{
		load_texture(game, &game->door_tex, line + 3);
		game->door_tex.flag++;
	}
}

static void	process_color_line(t_game *game, char *line)
{
	if (line[0] == 'F')
	{
		get_color(game, &game->floor, line + 2);
		game->floor.flag++;
	}
	else if (line[0] == 'C')
	{
		get_color(game, &game->ceiling, line + 2);
		game->ceiling.flag++;
	}
}

static void	process_single_line(t_game *game, char *line)
{
	process_texture_line(game, line);
	process_color_line(game, line);
}

static void	validate_texture_count(t_game *game)
{
	if (game->no.flag != 1 || game->so.flag != 1 || game->we.flag != 1
		|| game->ea.flag != 1 || game->floor.flag != 1
		|| game->ceiling.flag != 1)
		error_exit(game, "Error: invalid texture count\n");
	if (game->door_count > 0 && !game->door_tex.flag)
		error_exit(game, "Error: invalid texture count\n");
}

void	process_text_col(t_game *game, char **lines, int count, int map_flag)
{
	int		i;

	i = 0;
	while (i < count)
	{
		if (map_flag != -1 && i >= map_flag)
			break ;
		process_single_line(game, lines[i]);
		i++;
	}
	validate_texture_count(game);
}
