/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakkerma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:13:02 by lakkerma          #+#    #+#             */
/*   Updated: 2025/09/03 14:13:03 by lakkerma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

static void	set_player_ns(t_game *game, char direction)
{
	if (direction == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (direction == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
}

static void	set_player_ew(t_game *game, char direction)
{
	if (direction == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (direction == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

static void	process_map_char(t_game *game, char *trim, int x, int y)
{
	game->map[y][x] = trim[x];
	if (ft_strchr("NSEW", trim[x]))
	{
		game->player.pos_x = x + 0.5;
		game->player.pos_y = y + 0.5;
		if (trim[x] == 'N' || trim[x] == 'S')
			set_player_ns(game, trim[x]);
		else if (trim[x] == 'E' || trim[x] == 'W')
			set_player_ew(game, trim[x]);
	}
	if (trim[x] == 'X')
		bonus_sprite_pos(game, x, y);
}

static void	parse_map_line(t_game *game, char *line, int y)
{
	int		x;
	char	*trim;

	x = 0;
	trim = ft_strtrim(line, "\n");
	while (trim[x] && x < game->map_width)
	{
		process_map_char(game, trim, x, y);
		x++;
	}
	free(trim);
}

void	process_map(t_game *game, char **lines, int line_count, int map_flag)
{
	int		i;
	int		y;
	char	*line;

	if (map_flag == -1)
		error_exit(game, "Error: no map found\n");
	i = map_flag;
	y = 0;
	while (i < line_count && y < game->map_height)
	{
		line = lines[i];
		if (line[0] && ft_strchr("01NSEWXD ", line[0]))
		{
			if (!(line[0] == 'N' && line[1] == 'O') && !(line[0] == 'S'
					&& line[1] == 'O') && !(line[0] == 'W' && line[1] == 'E')
				&& !(line[0] == 'E' && line[1] == 'A') && !(line[0] == 'F'
					&& line[1] == ' ') && !(line[0] == 'C' && line[1] == ' ')
				&& !(line[0] == 'D' && line[1] == 'R'))
				parse_map_line(game, line, y++);
		}
		i++;
	}
}
