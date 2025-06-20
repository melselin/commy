/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:17 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/05 13:28:41 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_loop_end(game->mlx);
	}
	cleanup_game(game);
	printf("Game has been closed successfully.\n");
	exit(0);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_split2(t_game *game, char **str)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_map_grid(char **grid)
{
	int	i;

	if (grid == NULL)
		return ;
	i = 0;
	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
