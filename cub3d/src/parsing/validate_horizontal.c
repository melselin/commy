/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_horizontal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakkerma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:23:36 by lakkerma          #+#    #+#             */
/*   Updated: 2025/09/03 14:23:37 by lakkerma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

static int	handle_border_x(t_game *game, char current, int x, int y)
{
	if (current != '1' && current != ' ')
		return (0);
	if (current == ' ')
	{
		if (x == 0 && x + 1 < game->map_width
			&& ft_strchr("0NSEWXD", game->map[y][x + 1]))
			return (0);
		if (x == game->map_width - 1
			&& x - 1 >= 0 && ft_strchr("0NSEWXD", game->map[y][x - 1]))
			return (0);
	}
	return (1);
}

static int	handle_spaces_x(t_game *game, int x, int y)
{
	if (x > 0 && game->map[y][x - 1] != '1' && game->map[y][x - 1] != ' ')
		return (0);
	if (x < game->map_width - 1 && game->map[y][x + 1] != '1'
		&& game->map[y][x + 1] != ' ')
		return (0);
	if (x > 0 && ft_strchr("0NSEWXD", game->map[y][x - 1]))
		return (0);
	if (x < game->map_width - 1
		&& ft_strchr("0NSEWXD", game->map[y][x + 1]))
		return (0);
	return (1);
}

static int	handle_walkable_x(t_game *game, int x, int y)
{
	if (x > 0 && game->map[y][x - 1] == ' ')
		return (0);
	if (x < game->map_width - 1 && game->map[y][x + 1] == ' ')
		return (0);
	if (x == 0 || x == game->map_width - 1)
		return (0);
	return (1);
}

int	additional_checks_x(t_game *game, int y)
{
	int	x;
	int	last_x;

	x = 0;
	while (x < game->map_width && game->map[y][x] == ' ')
		x++;
	if (x < game->map_width && game->map[y][x] != '1')
		return (0);
	last_x = game->map_width - 1;
	while (last_x >= 0 && game->map[y][last_x] == ' ')
		last_x--;
	if (last_x >= 0 && game->map[y][last_x] != '1')
		return (0);
	return (1);
}

int	validate_row_cells(t_game *game, int y)
{
	int		x;
	char	current;

	x = 0;
	while (x < game->map_width)
	{
		current = game->map[y][x];
		if (x == 0 || x == game->map_width - 1)
		{
			if (!handle_border_x(game, current, x, y))
				return (0);
		}
		if (current == ' ')
		{
			if (!handle_spaces_x(game, x, y))
				return (0);
		}
		if (ft_strchr("0NSEWXD", current))
		{
			if (!handle_walkable_x(game, x, y))
				return (0);
		}
		x++;
	}
	return (1);
}
