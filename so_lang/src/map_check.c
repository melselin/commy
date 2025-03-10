/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:51 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:01:05 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_player_character(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'P')
	{
		game->map.player_count++;
		game->map.player_x = x;
		game->map.player_y = y;
		if (game->map.player_count > 1)
			error_exit("Map must contain exactly one player", game);
	}
}

void	check_exit_character(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'E')
	{
		game->map.exit_count++;
		if (game->map.exit_count > 1)
			error_exit("Map must contain exactly one exit", game);
	}
}

void	check_collectible_character(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'C')
		game->map.collectible_count++;
}

void	check_special_characters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			check_player_character(game, x, y);
			check_exit_character(game, x, y);
			check_collectible_character(game, x, y);
			x++;
		}
		y++;
	}
}

void	check_set_map(t_game *game)
{
	check_valid_characters(game);
	check_special_characters(game);
}
