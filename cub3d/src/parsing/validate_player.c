/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakkerma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:58:23 by lakkerma          #+#    #+#             */
/*   Updated: 2025/09/04 12:58:24 by lakkerma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

int	is_element_line(char *line)
{
	if ((line[0] == 'N' && line[1] == 'O') || (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'W' && line[1] == 'E') || (line[0] == 'E'
			&& line[1] == 'A') || (line[0] == 'F' && line[1] == ' ')
		|| (line[0] == 'C' && line[1] == ' ') || (line[0] == 'D'
			&& line[1] == 'R'))
		return (1);
	return (0);
}

static int	count_players_in_line(char *line)
{
	int		x;
	int		count;
	char	*trim;

	x = 0;
	count = 0;
	trim = ft_strtrim(line, "\n");
	while (trim[x])
	{
		if (trim[x] == 'N' || trim[x] == 'S' || trim[x] == 'E'
			|| trim[x] == 'W')
			count++;
		x++;
	}
	free(trim);
	return (count);
}

void	validate_player_count(t_game *game, char **lines, int line_count,
		int map_flag)
{
	int		i;
	int		player_count;
	char	*line;

	player_count = 0;
	if (map_flag == -1)
		return ;
	i = map_flag;
	while (i < line_count)
	{
		line = lines[i];
		if (line[0] && ft_strchr("01NSEWXD ", line[0])
			&& !is_element_line(line))
		{
			player_count += count_players_in_line(line);
		}
		i++;
	}
	if (player_count == 0)
		error_exit(game, "Error: no player start position\n");
	if (player_count > 1)
		error_exit(game, "Error: multiple player start positions\n");
}
