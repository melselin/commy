/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:30:58 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:31:00 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

void	move_forward(t_game *game, double *new_x, double *new_y)
{
	t_move	move;

	move.new_x = new_x;
	move.new_y = new_y;
	move.dir_x = game->player.dir_x;
	move.dir_y = game->player.dir_y;
	move_player(game, &move);
}

void	move_backward(t_game *game, double *new_x, double *new_y)
{
	t_move	move;

	move.new_x = new_x;
	move.new_y = new_y;
	move.dir_x = -game->player.dir_x;
	move.dir_y = -game->player.dir_y;
	move_player(game, &move);
}

void	move_left(t_game *game, double *new_x, double *new_y)
{
	t_move	move;

	move.new_x = new_x;
	move.new_y = new_y;
	move.dir_x = game->player.dir_y;
	move.dir_y = -game->player.dir_x;
	move_player(game, &move);
}

void	move_right(t_game *game, double *new_x, double *new_y)
{
	t_move	move;

	move.new_x = new_x;
	move.new_y = new_y;
	move.dir_x = -game->player.dir_y;
	move.dir_y = game->player.dir_x;
	move_player(game, &move);
}

void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(angle) - player->plane_y
		* sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}
