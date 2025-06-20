/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:57:01 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:01:24 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	error_exit(const char *message, t_game *game)
{
	ft_printf("Error\n%s\n", message);
	if (game->map_malloc == true)
		close_window(game);
	if (game)
		cleanup_game(game);
	exit(EXIT_FAILURE);
}

void	check_empty_line(t_game *game, char *map)
{
	int	i;

	if (!map || map[0] == '\n')
		error_exit("Invalid Map: Empty line at start", game);
	if (map[ft_strlen(map) - 1] == '\n' && map[ft_strlen(map) - 2] == '\n')
	{
		free(map);
		error_exit("Invalid Map: Empty line at end", game);
	}
	i = 0;
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			error_exit("Invalid Map: Empty line inside", game);
		}
		i++;
	}
}

void	check_arg(int argc, char **argv, t_game *game)
{
	int	len;

	game->map_malloc = false;
	if (argc > 2)
		error_exit("Too much arguments", game);
	else if (argc < 2)
		error_exit("Missing map", game);
	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4) != 0)
		error_exit("Map extension is wrong", game);
}
