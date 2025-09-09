/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:23:57 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:24:01 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"
/*
** Count total sprites in a line
*/
void	bonus_count_store_sprites(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'X')
			game->total_sprites++;
		i++;
	}
}

/*
** Count total doors in a line
*/
void	bonus_count_doors(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'D' && line[i + 1] != 'R')
			game->door_count++;
		i++;
	}
}

/*
** Allocate memory for sprites
*/
void	bonus_mem_sprite(t_game *game)
{
	if (game->total_sprites > 0)
	{
		game->sprites = malloc(sizeof(t_sprite) * game->total_sprites);
		if (!game->sprites)
			error_exit(game, "Error: malloc sprites failed\n");
		game->sprite_count = 0;
	}
}

void	bonus_mem_doors(t_game *game)
{
	if (game->door_count > 0)
	{
		game->doors = malloc(sizeof(t_door) * game->door_count);
		if (!game->doors)
			error_exit(game, "Error: malloc doors failed\n");
	}
}

/*
** Store sprite position in game
*/
void	bonus_sprite_pos(t_game *game, int x, int y)
{
	if (!game->sprites)
		return ;
	if (game->sprite_count >= game->total_sprites)
		return ;
	ft_bzero(&game->sprites[game->sprite_count], sizeof(t_sprite));
	game->sprites[game->sprite_count].x = x + 0.5;
	game->sprites[game->sprite_count].y = y + 0.5;
	game->sprites[game->sprite_count].angle = (double)(game->sprite_count)
		* 1.0;
	if (game->map && game->map[(int)y][(int)x] == 'X')
		game->sprites[game->sprite_count].tex = game->enemy_tex;
	game->sprite_count++;
}
