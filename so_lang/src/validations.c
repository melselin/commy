/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:57:04 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:57:55 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	validate_exit(t_map *map, t_game *game)
{
	int	exit_count;
	int	y;
	int	x;

	exit_count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'E')
			{
				exit_count++;
				if (exit_count > 1)
					error_exit("Map must contain exactly one exit\n", game);
			}
			x++;
		}
		y++;
	}
	if (exit_count != 1)
		error_exit("Map must contain exactly one exit\n", game);
	return (1);
}

void	validate_chara(t_game *game, t_map *map, int y, int x)
{
	char	c;

	c = map->grid[y][x];
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		error_exit("Invalid character in map\n", game);
}

int	validate_player(t_map *map, t_game *game, int y, int x)
{
	static int	player_count = 0;
	char		c;

	c = map->grid[y][x];
	if (c == 'P')
	{
		player_count++;
		map->player_x = x;
		map->player_y = y;
		if (player_count > 1)
			error_exit("Map must contain exactly one player\n", game);
	}
	return (player_count);
}

void	validate_map_grid(t_map *map, t_game *game)
{
	int	x;
	int	y;
	int	player_count;

	player_count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			validate_chara(game, map, y, x);
			player_count = validate_player(map, game, y, x);
			x++;
		}
		y++;
	}
	if (player_count != 1)
		error_exit("Map must contain exactly one player\n", game);
}

int	validate_map(t_map *map, t_game *game)
{
	validate_map_grid(map, game);
	return (validate_exit(map, game));
}
