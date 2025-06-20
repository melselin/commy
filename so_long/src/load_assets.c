/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:48 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:01:00 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	load_assets(t_game *game)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&game->img_width, &game->img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
			&game->img_width, &game->img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"assets/collectible.xpm", &game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm",
			&game->img_width, &game->img_height);
	game->scores_img = mlx_xpm_file_to_image(game->mlx, "assets/scores.xpm",
			&game->img_width, &game->img_height);
	if (!load_sprites(game))
	{
		cleanup_images(game);
		return (0);
	}
	if (!game->wall_img || !game->floor_img || !game->collectible_img
		|| !game->exit_img || !game->scores_img)
	{
		cleanup_images(game);
		return (0);
	}
	return (1);
}

int	load_player_sprites(t_game *game)
{
	game->player_frames[0][0] = mlx_xpm_file_to_image(game->mlx,
			"assets/player_up_1.xpm", &game->img_width, &game->img_height);
	game->player_frames[0][1] = mlx_xpm_file_to_image(game->mlx,
			"assets/player_up_2.xpm", &game->img_width, &game->img_height);
	game->player_frames[1][0] = mlx_xpm_file_to_image(game->mlx,
			"assets/player_right_1.xpm", &game->img_width, &game->img_height);
	game->player_frames[1][1] = mlx_xpm_file_to_image(game->mlx,
			"assets/player_right_2.xpm", &game->img_width, &game->img_height);
	game->player_frames[2][0] = mlx_xpm_file_to_image(game->mlx,
			"assets/player_down_1.xpm", &game->img_width, &game->img_height);
	game->player_frames[2][1] = mlx_xpm_file_to_image(game->mlx,
			"assets/player_down_2.xpm", &game->img_width, &game->img_height);
	game->player_frames[3][0] = mlx_xpm_file_to_image(game->mlx,
			"assets/player_left_1.xpm", &game->img_width, &game->img_height);
	game->player_frames[3][1] = mlx_xpm_file_to_image(game->mlx,
			"assets/player_left_2.xpm", &game->img_width, &game->img_height);
	return (1);
}

int	load_enemy_sprites(t_game *game)
{
	game->enemy_frames[0][0] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy_up_1.xpm", &game->img_width, &game->img_height);
	game->enemy_frames[0][1] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy_up_2.xpm", &game->img_width, &game->img_height);
	game->enemy_frames[1][0] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy_right_1.xpm", &game->img_width, &game->img_height);
	game->enemy_frames[1][1] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy_right_2.xpm", &game->img_width, &game->img_height);
	game->enemy_frames[2][0] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy_down_1.xpm", &game->img_width, &game->img_height);
	game->enemy_frames[2][1] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy_down_2.xpm", &game->img_width, &game->img_height);
	game->enemy_frames[3][0] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy_left_1.xpm", &game->img_width, &game->img_height);
	game->enemy_frames[3][1] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy_left_2.xpm", &game->img_width, &game->img_height);
	return (1);
}

int	validate_sprites(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 2)
		{
			if (!game->player_frames[i][j] || !game->enemy_frames[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	load_sprites(t_game *game)
{
	if (!load_player_sprites(game))
	{
		cleanup_images(game);
		return (0);
	}
	if (!load_enemy_sprites(game))
	{
		cleanup_images(game);
		return (0);
	}
	if (!validate_sprites(game))
	{
		cleanup_images(game);
		return (0);
	}
	return (1);
}
