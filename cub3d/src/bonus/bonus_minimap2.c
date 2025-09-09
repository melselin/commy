/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:23:49 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:23:52 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"
/*
** Check if a point is within the minimap circle
*/
int	is_in_circle(t_circle_check *circle)
{
	int	dx;
	int	dy;

	dx = circle->x - circle->center_x;
	dy = circle->y - circle->center_y;
	return (dx * dx + dy * dy <= circle->radius * circle->radius);
}

/*
** Draw a single pixel if within circle bounds
*/
void	draw_minimap_pixel(t_game *game, t_minimap_pixel *pixel)
{
	t_circle_check	circle;

	circle.x = pixel->px;
	circle.y = pixel->py;
	circle.center_x = MINIMAP_CENTER_X;
	circle.center_y = MINIMAP_CENTER_Y;
	circle.radius = MINIMAP_RADIUS;
	if (pixel->px >= 0 && pixel->px < WIN_WIDTH && pixel->py >= 0
		&& pixel->py < WIN_HEIGHT && is_in_circle(&circle))
		*(int *)(game->img_data + pixel->py * game->img_line + pixel->px
				* (game->pixel_bits / 8)) = pixel->color;
}

/*
** Draw a cell in the focused minimap
*/
void	draw_focused_cell(t_minimap_draw *params)
{
	t_minimap_pixel	pixel;

	if (params->map_x < 0 || params->map_x >= params->game->map_width
		|| params->map_y < 0 || params->map_y >= params->game->map_height)
		return ;
	if (params->game->map[params->map_y][params->map_x] == '1'
		|| params->game->map[params->map_y][params->map_x] == 'X')
		return ;
	pixel.color = 0xFF69B4;
	pixel.dy = 0;
	while (pixel.dy < MINIMAP_CELL_SIZE)
	{
		pixel.dx = 0;
		while (pixel.dx < MINIMAP_CELL_SIZE)
		{
			pixel.px = params->screen_x + pixel.dx;
			pixel.py = params->screen_y + pixel.dy;
			draw_minimap_pixel(params->game, &pixel);
			pixel.dx++;
		}
		pixel.dy++;
	}
}

/*
** Draw player in focused minimap
*/
void	draw_focused_player(t_game *game, int screen_x, int screen_y)
{
	t_minimap_pixel	pixel;

	pixel.color = 0xFF0000;
	pixel.dy = -3;
	while (pixel.dy <= 3)
	{
		pixel.dx = -3;
		while (pixel.dx <= 3)
		{
			pixel.px = screen_x + pixel.dx;
			pixel.py = screen_y + pixel.dy;
			draw_minimap_pixel(game, &pixel);
			pixel.dx++;
		}
		pixel.dy++;
	}
}
