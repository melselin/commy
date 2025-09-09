/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakkerma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:29:06 by lakkerma          #+#    #+#             */
/*   Updated: 2025/09/03 14:29:06 by lakkerma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

static int	validate_horizontal(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		if (!validate_row_cells(game, y))
			return (0);
		if (!additional_checks_x(game, y))
			return (0);
		y++;
	}
	return (1);
}

static int	validate_vertical(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map_width)
	{
		if (!validate_line_cells(game, x))
			return (0);
		if (!additional_checks_y(game, x))
			return (0);
		x++;
	}
	return (1);
}

void	validate_map(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			c = game->map[y][x];
			if (!ft_strchr("01NSEWXD ", c))
				error_exit(game, "Error: invalid character in map\n");
			x++;
		}
		y++;
	}
	if (!validate_horizontal(game))
		error_exit(game, "Error: map is not enclosed horizontally\n");
	if (!validate_vertical(game))
		error_exit(game, "Error: map is not enclosed vertically\n");
}
