/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:55 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:01:14 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	read_map_file(const char *path, t_game *game, char **map_tmp)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit("Error opening map file\n", game);
	*map_tmp = ft_strdup("");
	game->map.height = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '\0')
		{
			*map_tmp = ft_strappend(map_tmp, line);
			game->map.height++;
		}
		free(line);
	}
	close(fd);
	if (game->map.height == 0)
		error_exit("Map file is empty\n", game);
	return (game->map.height);
}

int	count_lines(const char *path, t_game *game)
{
	char	*map_tmp;
	int		height;

	height = read_map_file(path, game, &map_tmp);
	free(map_tmp);
	return (height);
}

int	start_load_map(t_game *game, const char *path)
{
	game->map.height = count_lines(path, game);
	if (game->map.height == 0)
		error_exit("Map file is empty\n", game);
	free(game->map.grid);
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		error_exit("Memory allocation failed\n", game);
	return (1);
}
