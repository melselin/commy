/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:22:44 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:22:48 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"
/*
** Apply push between two overlapping enemies
*/
static void	apply_enemy_push(t_sprite *a, t_sprite *b)
{
	double	dx;
	double	dy;
	double	dist;
	double	push;

	dx = a->x - b->x;
	dy = a->y - b->y;
	dist = sqrt(dx * dx + dy * dy);
	if (dist < 0.5)
	{
		push = 0.5 - dist;
		a->x += (dx / dist) * push * 2.0;
		a->y += (dy / dist) * push * 2.0;
	}
}

/*
** Randomly change enemy direction
*/
static void	randomize_enemy_direction(t_sprite *a)
{
	int	r;

	r = rand() % 3;
	if (r == 0)
		a->visible = 1;
	else if (r == 1)
		a->visible = -1;
	else if (rand() % 2 == 0)
		a->visible = 1;
	else
		a->visible = -1;
}

/*
** Main collision check
*/
void	check_enemy_collision(t_sprite *a, t_sprite *b)
{
	double	dx;
	double	dy;
	double	dist;

	dx = a->x - b->x;
	dy = a->y - b->y;
	dist = sqrt(dx * dx + dy * dy);
	if (dist < 0.5)
	{
		apply_enemy_push(a, b);
		randomize_enemy_direction(a);
	}
}

/*
** Check if map tile is a wall
*/
int	is_wall(t_game *game, double x, double y)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
	if (!game || !game->map)
		return (1);
	if (mx < 0 || my < 0 || mx >= game->map_width || my >= game->map_height)
		return (1);
	if (game->map[my][mx] == '1')
		return (1);
	return (0);
}

/*
** Check collision with other enemies
*/
int	is_enemy_collision(t_game *game, int idx, double x, double y)
{
	int	i;

	i = 0;
	while (i < game->sprite_count)
	{
		if (i != idx)
		{
			if (fabs(game->sprites[i].x - x) < 0.5
				&& fabs(game->sprites[i].y - y) < 0.5)
				return (1);
		}
		i++;
	}
	return (0);
}
