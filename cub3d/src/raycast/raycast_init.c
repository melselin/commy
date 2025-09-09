/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:28:45 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 15:29:09 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

void	init_step_side(t_raycast_init *init_data, t_step_side *step_side)
{
	if (init_data->ray_dir.x < 0)
	{
		step_side->step_x = -1;
		step_side->side_dist_x = (init_data->game->player.pos_x
				- init_data->map_pos.x) * init_data->delta_dist.x;
	}
	else
	{
		step_side->step_x = 1;
		step_side->side_dist_x = (init_data->map_pos.x + 1.0
				- init_data->game->player.pos_x) * init_data->delta_dist.x;
	}
	if (init_data->ray_dir.y < 0)
	{
		step_side->step_y = -1;
		step_side->side_dist_y = (init_data->game->player.pos_y
				- init_data->map_pos.y) * init_data->delta_dist.y;
	}
	else
	{
		step_side->step_y = 1;
		step_side->side_dist_y = (init_data->map_pos.y + 1.0
				- init_data->game->player.pos_y) * init_data->delta_dist.y;
	}
}
