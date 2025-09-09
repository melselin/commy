/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_vertical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakkerma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:59:07 by lakkerma          #+#    #+#             */
/*   Updated: 2025/09/04 12:59:07 by lakkerma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

static int	handle_border_y(t_game *game, char current, int x, int y)
{
	if (current != '1' && current != ' ')
		return (0);
	if (current == ' ')
	{
		if (y == 0 && y + 1 < game->map_height
			&& ft_strchr("0NSEWXD", game->map[y + 1][x]))
			return (0);
		if (y == game->map_height - 1 && y - 1 >= 0
			&& ft_strchr("0NSEWXD", game->map[y - 1][x]))
			return (0);
	}
	return (1);
}

static int	handle_spaces_y(t_game *game, int x, int y)
{
	if (y > 0 && game->map[y - 1][x] != '1' && game->map[y - 1][x] != ' ')
		return (0);
	if (y < game->map_height - 1 && game->map[y + 1][x] != '1'
		&& game->map[y + 1][x] != ' ')
		return (0);
	if (y > 0 && ft_strchr("0NSEWXD", game->map[y - 1][x]))
		return (0);
	if (y < game->map_height - 1 && ft_strchr("0NSEWXD", game->map[y + 1][x]))
		return (0);
	return (1);
}

static int	handle_walkable_y(t_game *game, int x, int y)
{
	if (y > 0 && game->map[y - 1][x] == ' ')
		return (0);
	if (y < game->map_height - 1 && game->map[y + 1][x] == ' ')
		return (0);
	if (y == 0 || y == game->map_height - 1)
		return (0);
	return (1);
}

int	additional_checks_y(t_game *game, int x)
{
	int	y;
	int	last_y;

	y = 0;
	while (y < game->map_height && game->map[y][x] == ' ')
		y++;
	if (y < game->map_height && game->map[y][x] != '1')
		return (0);
	last_y = game->map_height - 1;
	while (last_y >= 0 && game->map[last_y][x] == ' ')
		last_y--;
	if (last_y >= 0 && game->map[last_y][x] != '1')
		return (0);
	return (1);
}

int	validate_line_cells(t_game *game, int x)
{
	int		y;
	char	current;

	y = 0;
	while (y < game->map_height)
	{
		current = game->map[y][x];
		if (y == 0 || y == game->map_height - 1)
		{
			if (!handle_border_y(game, current, x, y))
				return (0);
		}
		if (current == ' ')
		{
			if (!handle_spaces_y(game, x, y))
				return (0);
		}
		if (ft_strchr("0NSEWXD", current))
		{
			if (!handle_walkable_y(game, x, y))
				return (0);
		}
		y++;
	}
	return (1);
}
