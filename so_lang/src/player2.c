/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:58 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:01:19 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	calculate_new_pos(t_game *game, t_direction dir, int *new_x, int *new_y)
{
	*new_x = game->map.player_x + dir.dx;
	*new_y = game->map.player_y + dir.dy;
}

int	can_move(t_game *game, int new_x, int new_y)
{
	char	cell;

	if (new_x < 0 || new_x >= game->map.width || new_y < 0
		|| new_y >= game->map.height)
	{
		return (0);
	}
	cell = game->map.grid[new_y][new_x];
	if (cell == '1')
	{
		return (0);
	}
	if (cell == 'E' && game->collected != game->map.collectible_count)
	{
		return (0);
	}
	return (1);
}

void	scan_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'P')
			{
				game->map.player_x = x;
				game->map.player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
