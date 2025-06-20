/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:17 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:32:48 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	cleanup_images(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 2)
		{
			if (game->player_frames[i][j])
				mlx_destroy_image(game->mlx, game->player_frames[i][j]);
			if (game->enemy_frames[i][j])
				mlx_destroy_image(game->mlx, game->enemy_frames[i][j]);
			j++;
		}
		i++;
	}
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
}

void	cleanup_game(t_game *game)
{
	if (game->map_malloc)
	{
		free_map_grid(game->map.grid);
		game->map_malloc = false;
	}
	cleanup_images(game);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->scores_img)
		mlx_destroy_image(game->mlx, game->scores_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free_map(&game->map);
	cleaner(game);
}

void	free_map(t_map *map)
{
	int	y;

	if (!map->grid)
		return ;
	y = 0;
	while (y < map->height)
	{
		if (map->grid[y])
			free(map->grid[y]);
		y++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	cleaner(t_game *game)
{
	int	y;

	if (game->map.visited)
	{
		y = 0;
		while (y < game->map.height)
		{
			free(game->map.visited[y]);
			y++;
		}
		free(game->map.visited);
		game->map.visited = NULL;
	}
}
