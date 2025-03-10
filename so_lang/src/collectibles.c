/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:24 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:00:11 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	count_collectibles(t_game *game)
{
	int	collectible_count;
	int	y;
	int	x;

	collectible_count = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'C')
				collectible_count++;
			x++;
		}
		y++;
	}
	ft_printf("Total collectibles on map: %d\n", collectible_count);
	return (collectible_count);
}

void	check_collectible(t_game *game, char next_cell)
{
	if (next_cell == 'C')
	{
		game->collected++;
		ft_printf("Collectible collected! Total collected: %d/%d\n",
			game->collected, game->map.collectible_count);
	}
}
