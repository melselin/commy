/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:23:23 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:23:30 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"
/*
** Check if enemy can move to target position without hitting a wall
** or colliding with another enemy. Returns 1 if free, 0 if blocked.
*/
static int	can_move_to(t_game *game, int idx, double x, double y)
{
	double	buf;

	buf = 0.5;
	if (is_wall(game, x + buf, y + buf))
		return (0);
	if (is_wall(game, x - buf, y - buf))
		return (0);
	if (is_enemy_collision(game, idx, x, y))
		return (0);
	return (1);
}

/*
** Move enemy towards the player if within chase distance.
** Returns 1 if moved, 0 otherwise.
*/
static int	enemy_chase(t_game *game, int i, double dx, double dy)
{
	double	len;
	double	new_x;
	double	new_y;

	len = sqrt(dx * dx + dy * dy);
	if (len >= 3.0 || len < 1.5)
		return (0);
	dx /= len;
	dy /= len;
	new_x = game->sprites[i].x + dx * 0.03;
	new_y = game->sprites[i].y + dy * 0.03;
	if (can_move_to(game, i, new_x, new_y))
	{
		game->sprites[i].x = new_x;
		game->sprites[i].y = new_y;
		return (1);
	}
	return (0);
}

/*
** Patrol movement for enemy when not chasing player.
** Enemy moves in a circular pattern. Returns 1 if moved, 0 otherwise.
*/
static int	enemy_patrol(t_game *game, int i)
{
	double	new_x;
	double	new_y;

	game->sprites[i].angle += 0.03;
	new_x = game->sprites[i].x + cos(game->sprites[i].angle) * 0.02;
	new_y = game->sprites[i].y + sin(game->sprites[i].angle) * 0.02;
	if (can_move_to(game, i, new_x, new_y))
	{
		game->sprites[i].x = new_x;
		game->sprites[i].y = new_y;
		return (1);
	}
	return (0);
}

/*
** Update enemy texture based on movement and animation frame.
*/
static void	enemy_anim(t_game *game, int i, int moved, int anim_frame)
{
	if (!moved)
		game->sprites[i].tex = game->idle_tex;
	else if (game->enemy_tex.data && anim_frame % 40 < 20)
		game->sprites[i].tex = game->enemy_tex;
	else
		game->sprites[i].tex = game->sprite_tex;
}

/*
** Main function: update all enemies each frame.
** Handles chasing, patrolling, and updating textures.
*/
void	update_enemies(t_game *game)
{
	t_enemy_update	eu;
	static int		anim_frame = 0;

	if (!game || !game->sprites)
		return ;
	eu.i = -1;
	anim_frame++;
	while (++eu.i < game->sprite_count)
	{
		eu.dx = game->player.pos_x - game->sprites[eu.i].x;
		eu.dy = game->player.pos_y - game->sprites[eu.i].y;
		eu.len = sqrt(eu.dx * eu.dx + eu.dy * eu.dy);
		if (eu.len < 1.5)
			game->sprites[eu.i].tex = game->idle_tex;
		else
		{
			eu.moved = enemy_chase(game, eu.i, eu.dx, eu.dy);
			if (!eu.moved)
				eu.moved = enemy_patrol(game, eu.i);
			enemy_anim(game, eu.i, eu.moved, anim_frame);
		}
	}
}
