/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:51 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:01:05 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_row(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		if (game->map.grid[i][0] != '1')
			error_exit("Wall incomplete at row start", game);
		else if (game->map.grid[i][game->map.width - 1] != '1')
			error_exit("Wall incomplete at row end", game);
		i++;
	}
}

void	check_column(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.grid[0][i] != '1')
			error_exit("Wall incomplete at column start", game);
		if (game->map.grid[game->map.height - 1][i] != '1')
			error_exit("Wall incomplete at column end", game);
		i++;
	}
}

void	check_valid_characters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (!ft_strchr("01CEPX", game->map.grid[y][x]))
				error_exit("Invalid character in map", game);
			x++;
		}
		y++;
	}
}

int	validate_map_characters(t_game *game, t_map *map, int y, int x)
{
	char	c;
	int		is_top_or_bottom;
	int		is_left_or_right;

	c = map->grid[y][x];
	if (!ft_strchr("01CEPX", c))
		error_exit("Invalid character in map\n", game);
	is_top_or_bottom = (y == 0 || y == map->height - 1);
	is_left_or_right = (x == 0 || x == map->width - 1);
	if ((is_top_or_bottom || is_left_or_right) && c != '1')
		error_exit("Map must be surrounded by walls\n", game);
	return (1);
}
