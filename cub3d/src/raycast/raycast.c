/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:08:44 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 16:14:33 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

void	init_raycast_vars(t_raycast_vars *vars, t_game *game, int x)
{
	vars->x = x;
	vars->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	vars->ray_dir.x = game->player.dir_x
		+ game->player.plane_x * vars->camera_x;
	vars->ray_dir.y = game->player.dir_y
		+ game->player.plane_y * vars->camera_x;
	vars->map_pos.x = (int)game->player.pos_x;
	vars->map_pos.y = (int)game->player.pos_y;
}

void	perform_wall_calculation(t_game *game, t_raycast_vars *vars,
			t_wall_calc *wall_calc)
{
	t_raycast_init	init_data;
	t_dda_data		dda_data;
	t_dda_result	dda_result;

	wall_calc->delta_dist.x = fabs(1 / vars->ray_dir.x);
	wall_calc->delta_dist.y = fabs(1 / vars->ray_dir.y);
	init_data.game = game;
	init_data.ray_dir = vars->ray_dir;
	init_data.map_pos = vars->map_pos;
	init_data.delta_dist = wall_calc->delta_dist;
	init_step_side(&init_data, &vars->step_side);
	dda_data.game = game;
	dda_data.ray_dir = &vars->ray_dir;
	dda_data.map_pos = &vars->map_pos;
	dda_data.step_side = &vars->step_side;
	dda_data.delta_dist = &wall_calc->delta_dist;
	dda_result = perform_dda_algorithm(&dda_data);
	wall_calc->side = dda_result.side;
	wall_calc->is_door = dda_result.is_door;
	wall_calc->hit_door = dda_result.hit_door;
	calculate_wall_distance(game, vars, wall_calc);
}

void	calculate_wall_distance(t_game *game, t_raycast_vars *vars,
			t_wall_calc *wall_calc)
{
	if (wall_calc->side == 0)
		wall_calc->perp_wall_dist = (vars->map_pos.x - game->player.pos_x
				+ (1 - vars->step_side.step_x) / 2) / vars->ray_dir.x;
	else
		wall_calc->perp_wall_dist = (vars->map_pos.y - game->player.pos_y
				+ (1 - vars->step_side.step_y) / 2) / vars->ray_dir.y;
}

void	calculate_render_data(t_game *game, t_raycast_vars *vars,
			t_wall_calc *wall_calc, t_render_data *render)
{
	render->line_height = (int)(WIN_HEIGHT / wall_calc->perp_wall_dist);
	render->draw_start = -render->line_height / 2 + WIN_HEIGHT / 2;
	if (render->draw_start < 0)
		render->draw_start = 0;
	render->draw_end = render->line_height / 2 + WIN_HEIGHT / 2;
	if (render->draw_end >= WIN_HEIGHT)
		render->draw_end = WIN_HEIGHT - 1;
	if (wall_calc->is_door && wall_calc->hit_door)
		render->tex = &game->door_tex;
	else if (wall_calc->side == 0 && vars->ray_dir.x > 0)
		render->tex = &game->ea;
	else if (wall_calc->side == 0 && vars->ray_dir.x < 0)
		render->tex = &game->we;
	else if (wall_calc->side == 1 && vars->ray_dir.y > 0)
		render->tex = &game->so;
	else
		render->tex = &game->no;
	if (wall_calc->side == 0)
		render->wall_x = game->player.pos_y
			+ wall_calc->perp_wall_dist * vars->ray_dir.y;
	else
		render->wall_x = game->player.pos_x
			+ wall_calc->perp_wall_dist * vars->ray_dir.x;
	render->wall_x -= floor(render->wall_x);
}

void	raycast(t_game *game)
{
	t_raycast_vars	vars;
	t_wall_calc		wall_calc;
	t_render_data	render;

	vars.x = 0;
	while (vars.x < WIN_WIDTH)
	{
		init_raycast_vars(&vars, game, vars.x);
		perform_wall_calculation(game, &vars, &wall_calc);
		calculate_render_data(game, &vars, &wall_calc, &render);
		render_wall_column(game, &vars, &render, &wall_calc);
		game->z_buffer[vars.x] = wall_calc.perp_wall_dist;
		vars.x++;
	}
}
