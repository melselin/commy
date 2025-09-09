/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:29:22 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/07 16:39:33 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2 || !arg_check(argv[1]))
		error_exit(&game, "Usage: ./cub3D <map.cub>");
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		error_exit(&game, "Failed to initialize miniLibX");
	parse_map(&game, argv[1]);
	game.win_ptr = mlx_new_window(game.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game.win_ptr)
		error_exit(&game, "Failed to create window");
	game.img_ptr = mlx_new_image(game.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	game.img_data = mlx_get_data_addr(game.img_ptr, &game.pixel_bits,
			&game.img_line, &game.pixel_endian);
	game.z_buffer = malloc(sizeof(double) * WIN_WIDTH);
	if (!game.z_buffer)
		error_exit(&game, "Failed to allocate z_buffer");
	mlx_hook(game.win_ptr, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win_ptr, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win_ptr, 6, 1L << 6, mouse_hook, &game);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
