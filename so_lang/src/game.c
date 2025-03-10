/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:45 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:00:55 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	init_game(t_game *game, const char *map_path)
{
	int	window_width;
	int	window_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("MLX initialization failed\n", game);
	if (!load_map(game, map_path))
		error_exit("Failed to load map\n", game);
	if (!load_assets(game))
		error_exit("Failed to load assets\n", game);
	scan_player(game);
	window_width = game->map.width * TILE_SIZE;
	window_height = game->map.height * TILE_SIZE + 100;
	game->win = mlx_new_window(game->mlx, window_width, window_height,
			"so_long");
	if (!game->win)
		error_exit("Window creation failed\n", game);
	draw_map(game);
	game->moves = 0;
	draw_moves(game);
	return (1);
}

int	handle_input(int keycode, t_game *game)
{
	scan_player(game);
	if (keycode == ESC)
	{
		printf("Escape key pressed, exiting game\n");
		close_window(game);
		exit(0);
	}
	if (keycode == W_KEY || keycode == UP_ARROW)
		move_player(game, 0, -1);
	if (keycode == A_KEY || keycode == LEFT_ARROW)
		move_player(game, -1, 0);
	if (keycode == S_KEY || keycode == DOWN_ARROW)
		move_player(game, 0, 1);
	if (keycode == D_KEY || keycode == RIGHT_ARROW)
		move_player(game, 1, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	game.moves = 0;
	check_arg(argc, argv, &game);
	if (!init_game(&game, argv[1]))
	{
		return (1);
	}
	mlx_hook(game.win, 2, 1L << 0, handle_input, &game);
	mlx_hook(game.win, 17, 1L << 17, close_window, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}

int	game_loop(t_game *game)
{
	static int	frame_counter = 0;

	if (++frame_counter % 10 == 0)
	{
		game->current_frame = (game->current_frame + 1) % 2;
		draw_map(game);
		draw_player(game);
		draw_enemies(game);
		draw_moves(game);
	}
	return (0);
}
