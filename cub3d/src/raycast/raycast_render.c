/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:35:44 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 16:05:00 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

static int	get_tex_x(t_ray_result *ray, t_texture *tex, t_game *game)
{
	double	tex_pos;

	if (ray->side == 0)
		tex_pos = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		tex_pos = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	tex_pos -= floor(tex_pos);
	if ((ray->side == 0 && ray->ray_dir_x < 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		return (tex->width - (int)(tex_pos * tex->width) - 1);
	return ((int)(tex_pos * tex->width));
}

void	draw_column(t_game *game, t_texture *tex, t_column_draw *col,
		t_ray_result *ray)
{
	t_draw_vars	vars;

	vars.tex_x = get_tex_x(ray, tex, game);
	vars.step = 1.0 * tex->height / col->line_height;
	vars.tex_pos = (col->draw_start - WIN_HEIGHT / 2 + col->line_height / 2)
		* vars.step;
	vars.y = col->draw_start;
	while (vars.y < col->draw_end)
	{
		vars.tex_y = (int)vars.tex_pos & (tex->height - 1);
		vars.tex_pos += vars.step;
		vars.color = *(int *)(tex->data + vars.tex_y * tex->size_line
				+ vars.tex_x * (tex->bpp / 8));
		*(int *)(game->img_data + vars.y * game->img_line + col->x
				* (game->pixel_bits / 8)) = vars.color;
		vars.y++;
	}
}

void	render_wall_column(t_game *game, t_raycast_vars *vars,
			t_render_data *render, t_wall_calc *wall_calc)
{
	t_column_draw	col_draw;
	t_ray_result	ray_result;

	col_draw.x = vars->x;
	col_draw.draw_start = render->draw_start;
	col_draw.draw_end = render->draw_end;
	col_draw.line_height = render->line_height;
	ray_result.side = wall_calc->side;
	ray_result.perp_wall_dist = wall_calc->perp_wall_dist;
	ray_result.ray_dir_x = vars->ray_dir.x;
	ray_result.ray_dir_y = vars->ray_dir.y;
	draw_column(game, render->tex, &col_draw, &ray_result);
}
