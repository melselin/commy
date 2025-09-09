/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:23:39 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:23:41 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"
/*
** Draw a single pixel of the minimap border if it's within screen bounds
*/
void	draw_border_pixel(t_game *game, int x, int y)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		*(int *)(game->img_data + y * game->img_line + x * (game->pixel_bits
					/ 8)) = 0xFFFFFF;
}

/*
** Draw the circular border of the minimap
*/
void	draw_minimap_border(t_game *game)
{
	t_minimap_border	border;

	border.y = MINIMAP_CENTER_Y - MINIMAP_RADIUS - 2;
	while (border.y <= MINIMAP_CENTER_Y + MINIMAP_RADIUS + 2)
	{
		border.x = MINIMAP_CENTER_X - MINIMAP_RADIUS - 2;
		while (border.x <= MINIMAP_CENTER_X + MINIMAP_RADIUS + 2)
		{
			border.dx = border.x - MINIMAP_CENTER_X;
			border.dy = border.y - MINIMAP_CENTER_Y;
			border.dist_sq = border.dx * border.dx + border.dy * border.dy;
			if (border.dist_sq >= (MINIMAP_RADIUS - 1) * (MINIMAP_RADIUS - 1)
				&& border.dist_sq <= (MINIMAP_RADIUS + 1) * (MINIMAP_RADIUS
					+ 1))
				draw_border_pixel(game, border.x, border.y);
			border.x++;
		}
		border.y++;
	}
}

/*
** Draw minimap focused around player position
*/
void	draw_focused_minimap_cells(t_game *game)
{
	t_minimap_draw	draw_params;
	int				view_range;
	int				relative_x;
	int				relative_y;

	view_range = MINIMAP_RADIUS / MINIMAP_CELL_SIZE;
	draw_params.game = game;
	relative_y = -view_range;
	while (relative_y <= view_range)
	{
		relative_x = -view_range;
		while (relative_x <= view_range)
		{
			draw_params.map_x = (int)game->player.pos_x + relative_x;
			draw_params.map_y = (int)game->player.pos_y + relative_y;
			draw_params.screen_x = MINIMAP_CENTER_X - MINIMAP_CELL_SIZE / 2
				+ relative_x * MINIMAP_CELL_SIZE;
			draw_params.screen_y = MINIMAP_CENTER_Y - MINIMAP_CELL_SIZE / 2
				+ relative_y * MINIMAP_CELL_SIZE;
			draw_focused_cell(&draw_params);
			relative_x++;
		}
		relative_y++;
	}
}

void	draw_minimap(t_game *game)
{
	draw_focused_minimap_cells(game);
	draw_focused_player(game, MINIMAP_CENTER_X, MINIMAP_CENTER_Y);
	draw_minimap_border(game);
	draw_minimap_text(game, MINIMAP_CENTER_X - MINIMAP_RADIUS, MINIMAP_CENTER_Y
		+ MINIMAP_RADIUS + 40);
}
