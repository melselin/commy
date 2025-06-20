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

void	update_player_direction(t_game *game, int dx, int dy)
{
	if (dx == 0 && dy == -1)
		game->player_dir = 0;
	else if (dx == 1 && dy == 0)
		game->player_dir = 1;
	else if (dx == 0 && dy == 1)
		game->player_dir = 2;
	else if (dx == -1 && dy == 0)
		game->player_dir = 3;
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map.grid[game->map.player_y][game->map.player_x] = '0';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	game->map.grid[new_y][new_x] = 'P';
}

void	move_player(t_game *game, int dx, int dy)
{
	int			new_x;
	int			new_y;
	char		next_cell;
	t_direction	dir;

	dir.dx = dx;
	dir.dy = dy;
	update_player_direction(game, dx, dy);
	calculate_new_pos(game, dir, &new_x, &new_y);
	if (!can_move(game, new_x, new_y))
		return ;
	next_cell = game->map.grid[new_y][new_x];
	check_game_over(game, next_cell);
	check_victory(game, next_cell);
	update_player_position(game, new_x, new_y);
	check_collectible(game, next_cell);
	game->moves++;
	draw_moves(game);
	game->current_frame = (game->current_frame + 1) % 2;
	draw_player(game);
	move_enemies(game);
	enemy_collision(game);
}
