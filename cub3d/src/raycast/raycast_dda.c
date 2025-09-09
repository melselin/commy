/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:25:19 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 15:27:26 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

t_dda_result	perform_dda_algorithm(t_dda_data *dda_data)
{
	t_dda_result	result;

	result = (t_dda_result){0, 0, 0, NULL};
	while (!result.hit)
	{
		if (dda_data->map_pos->x < 0
			|| dda_data->map_pos->x >= dda_data->game->map_width
			|| dda_data->map_pos->y < 0
			|| dda_data->map_pos->y >= dda_data->game->map_height)
			break ;
		advance_dda(dda_data, &result);
		if (!check_hit_or_door(dda_data, &result))
			break ;
	}
	return (result);
}

void	advance_dda(t_dda_data *dda_data, t_dda_result *result)
{
	if (dda_data->step_side->side_dist_x < dda_data->step_side->side_dist_y)
	{
		dda_data->step_side->side_dist_x += dda_data->delta_dist->x;
		dda_data->map_pos->x += dda_data->step_side->step_x;
		result->side = 0;
	}
	else
	{
		dda_data->step_side->side_dist_y += dda_data->delta_dist->y;
		dda_data->map_pos->y += dda_data->step_side->step_y;
		result->side = 1;
	}
}

int	check_hit_or_door(t_dda_data *dda_data, t_dda_result *result)
{
	char	cell;

	if (dda_data->map_pos->x < 0
		|| dda_data->map_pos->x >= dda_data->game->map_width
		|| dda_data->map_pos->y < 0
		|| dda_data->map_pos->y >= dda_data->game->map_height)
		return (0);
	cell = dda_data->game->map[dda_data->map_pos->y][dda_data->map_pos->x];
	if (cell == '1')
		result->hit = 1;
	else if (cell == 'D')
		check_door_hit(dda_data, result);
	else if (cell == ' ')
		return (0);
	return (1);
}

void	check_door_hit(t_dda_data *dda_data, t_dda_result *result)
{
	double	wall_x;

	result->hit_door = get_door(dda_data->game, dda_data->map_pos->x,
			dda_data->map_pos->y);
	if (!result->hit_door)
		return ;
	if (result->side == 0)
		wall_x = dda_data->game->player.pos_y + ((dda_data->map_pos->x
					- dda_data->game->player.pos_x + (1
						- dda_data->step_side->step_x) / 2)
				/ dda_data->ray_dir->x) * dda_data->ray_dir->y;
	else
		wall_x = dda_data->game->player.pos_x + ((dda_data->map_pos->y
					- dda_data->game->player.pos_y + (1
						- dda_data->step_side->step_y) / 2)
				/ dda_data->ray_dir->y) * dda_data->ray_dir->x;
	wall_x -= floor(wall_x);
	if (wall_x > result->hit_door->open_progress)
	{
		result->hit = 1;
		result->is_door = 1;
	}
}
