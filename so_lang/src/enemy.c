/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:56:32 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/02 19:00:36 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	enemy_collision(t_game *game)
{
	if (game->map.grid[game->map.player_y][game->map.player_x] == 'X')
	{
		ft_printf("Game Over! You were caught by an enemy!\n");
		exit(0);
	}
	return (0);
}

void	set_enemy_direction(t_game *game, t_enemy *enemy)
{
	if (enemy->dx == 1)
		game->enemy_dir = 1;
	else if (enemy->dx == -1)
		game->enemy_dir = 3;
	else if (enemy->dy == 1)
		game->enemy_dir = 2;
	else if (enemy->dy == -1)
		game->enemy_dir = 0;
}

void	move_enemy(t_game *game, t_enemy *enemy)
{
	enemy->dx = 0;
	enemy->dy = 0;
	enemy->dir = rand() % 4;
	if (enemy->dir == 0 && game->map.grid[enemy->y][enemy->x + 1] == '0')
		enemy->dx = 1;
	if (enemy->dir == 1 && game->map.grid[enemy->y][enemy->x - 1] == '0')
		enemy->dx = -1;
	if (enemy->dir == 2 && game->map.grid[enemy->y + 1][enemy->x] == '0')
		enemy->dy = 1;
	if (enemy->dir == 3 && game->map.grid[enemy->y - 1][enemy->x] == '0')
		enemy->dy = -1;
	enemy->x += enemy->dx;
	enemy->y += enemy->dy;
	if (enemy->x == game->map.player_x && enemy->y == game->map.player_y)
	{
		ft_printf("Game Over! You were caught!\n");
		exit(0);
	}
	if (enemy->dx || enemy->dy)
	{
		game->map.grid[enemy->y - enemy->dy][enemy->x - enemy->dx] = '0';
		game->map.grid[enemy->y][enemy->x] = 'X';
		set_enemy_direction(game, enemy);
	}
}

void	move_enemies(t_game *game)
{
	static int	move_counter = 0;
	int			y;
	int			x;
	t_enemy		enemy;

	move_counter++;
	if (move_counter % 7 != 0)
		return ;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'X')
			{
				enemy.x = x;
				enemy.y = y;
				move_enemy(game, &enemy);
			}
			x++;
		}
		y++;
	}
	draw_map(game);
}
