/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:33:25 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:33:27 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

/*
** Draw ceiling part of the background
*/
static void	draw_ceiling(t_game *game)
{
	t_line	line;
	int		y;
	int		color;

	color = (game->ceiling.r << 16) | (game->ceiling.g << 8) | game->ceiling.b;
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		line.start_x = 0;
		line.end_x = WIN_WIDTH - 1;
		line.y = y;
		line.color = color;
		draw_line(game, line);
		y++;
	}
}

/*
** Draw floor part of the background
*/
static void	draw_floor(t_game *game)
{
	t_line	line;
	int		y;
	int		color;

	color = (game->floor.r << 16) | (game->floor.g << 8) | game->floor.b;
	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		line.start_x = 0;
		line.end_x = WIN_WIDTH - 1;
		line.y = y;
		line.color = color;
		draw_line(game, line);
		y++;
	}
}

/*
** Draw the full background by calling ceiling and floor draw functions
*/
void	draw_background(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
}

/*
** Draw a horizontal line on the image with bounds checking
*/
void	draw_line(t_game *game, t_line line)
{
	int	x;
	int	end_x;

	if (line.y < 0)
		line.y = 0;
	if (line.y >= WIN_HEIGHT)
		line.y = WIN_HEIGHT - 1;
	x = fmax(0, line.start_x);
	end_x = fmin(WIN_WIDTH - 1, line.end_x);
	while (x <= end_x)
	{
		*(int *)(game->img_data + line.y * game->img_line + x
				* (game->pixel_bits / 8)) = line.color;
		x++;
	}
}
