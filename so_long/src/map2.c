/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:55 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/05 13:28:52 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map_lines(t_game *game, int fd)
{
	int		y;
	char	*line;

	y = 0;
	while (y < game->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map.grid[y] = ft_strtrim(line, "\n");
		free(line);
		if (!game->map.grid[y] || ft_strlen(game->map.grid[y]) == 0)
		{
			free(game->map.grid);
			game->map.grid = NULL;
			error_exit("Invalid or empty line in map\n", game);
		}
		y++;
	}
	game->map.grid[y] = NULL;
	return (1);
}

int	validate_map_dimensions(t_game *game)
{
	int	y;

	game->map.width = ft_strlen(game->map.grid[0]);
	y = 0;
	while (y < game->map.height)
	{
		if ((int)ft_strlen(game->map.grid[y]) != game->map.width)
			error_exit("Inconsistent row lengths in map\n", game);
		y++;
	}
	return (1);
}

int	load_map(t_game *game, const char *path)
{
	int	fd;

	if (!start_load_map(game, path))
		error_exit("Failed to start loading map", game);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free_split(game->map.grid);
		error_exit("Error opening map file", game);
	}
	if (!read_map_lines(game, fd))
	{
		close(fd);
		free_split(game->map.grid);
		error_exit("Failed to read map lines", game);
	}
	close(fd);
	if (!validate_map_dimensions(game))
	{
		free_split(game->map.grid);
		error_exit("Map validation failed", game);
	}
	check_map(game);
	return (1);
}

void	check_parameters(t_game *game)
{
	if (game->map.collectible_count == 0)
		error_exit("Invalid Map: No coins found", game);
	if (game->map.exit_count == 0)
		error_exit("Invalid Map: No exit found", game);
	if (game->map.player_count != 1)
		error_exit("Invalid Map: More than one player", game);
}

void	check_map(t_game *game)
{
	check_row(game);
	check_column(game);
	check_set_map(game);
	check_parameters(game);
}
