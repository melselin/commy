/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:37 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:00:46 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_game_over(t_game *game, char next_cell)
{
	if (next_cell == 'X')
	{
		ft_printf("Game Over! You ran into an enemy!\n");
		game->game_over = 1;
		cleanup_game(game);
		exit(0);
	}
}

void	check_victory(t_game *game, char next_cell)
{
	if (next_cell == 'E' && game->collected == game->map.collectible_count)
	{
		ft_printf("You won in %d moves!\n", ++game->moves);
		cleanup_game(game);
		exit(0);
	}
}
