/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:28 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:00:25 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	draw_cell(t_game *game, char cell, int screen_x, int screen_y)
{
	if (cell == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, screen_x,
			screen_y);
	else if (cell == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible_img,
			screen_x, screen_y);
	else if (cell == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, screen_x,
			screen_y);
	else if (cell == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img, screen_x,
			screen_y);
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;
	char	cell;
	int		screen_x;
	int		screen_y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			cell = game->map.grid[y][x];
			screen_x = x * TILE_SIZE;
			screen_y = y * TILE_SIZE;
			draw_cell(game, cell, screen_x, screen_y);
			x++;
		}
		y++;
	}
	draw_player(game);
	draw_enemies(game);
}

void	draw_player(t_game *game)
{
	int	screen_x;
	int	screen_y;

	screen_x = game->map.player_x * TILE_SIZE;
	screen_y = game->map.player_y * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->player_frames[game->player_dir][game->current_frame], screen_x,
		screen_y);
}

void	draw_moves(t_game *game)
{
	char	move_count[50];
	int		text_x;
	int		text_y;
	int		scores_x;
	int		scores_y;

	sprintf(move_count, "Moves: %d", game->moves);
	scores_x = (game->map.width * TILE_SIZE - (10 - game->img_width)) / 2;
	scores_y = game->map.height * TILE_SIZE + (30 - game->img_height) / 2;
	mlx_put_image_to_window(game->mlx, game->win, game->scores_img, scores_x,
		scores_y);
	text_x = scores_x + (game->img_width - ft_strlen(move_count) * 10) / 2 + 90;
	text_y = scores_y + (game->img_height + 40) / 2;
	mlx_set_font(game->mlx, game->win, "9x15bold");
	mlx_string_put(game->mlx, game->win, text_x, text_y, 0x175017, move_count);
}

void	draw_enemies(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'X')
				mlx_put_image_to_window(game->mlx, game->win,
					game->enemy_frames[game->enemy_dir][game->current_frame], x
					* TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
