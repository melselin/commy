/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:33:31 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:33:33 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

void	door_interaction(t_game *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = (int)game->player.pos_x;
	y = (int)game->player.pos_y;
	while (i < game->door_count)
	{
		if (((abs(x - game->doors[i].x) <= 1 && y == game->doors[i].y)
				|| (abs(y - game->doors[i].y) <= 1 && x == game->doors[i].x)))
		{
			if (!game->doors[i].open && !game->doors[i].is_opening)
				game->doors[i].is_opening = 1;
		}
		else if (game->doors[i].open && !game->doors[i].is_closing)
			game->doors[i].is_closing = 1;
		i++;
	}
}

static void	process_opening_door(t_door *door, double speed)
{
	door->open_progress += speed;
	if (door->open_progress >= 1.0)
	{
		door->open_progress = 1.0;
		door->open = true;
		door->is_opening = 0;
	}
}

static void	process_closing_door(t_door *door, double speed)
{
	door->open_progress -= speed;
	if (door->open_progress <= 0.0)
	{
		door->open_progress = 0.0;
		door->open = false;
		door->is_closing = 0;
	}
}

void	update_doors(t_game *game)
{
	int		i;
	double	door_speed;

	i = 0;
	door_speed = 0.05;
	while (i < game->door_count)
	{
		if (game->doors[i].is_opening)
			process_opening_door(&game->doors[i], door_speed);
		else if (game->doors[i].is_closing)
			process_closing_door(&game->doors[i], door_speed);
		i++;
	}
}
