/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakkerma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:11:37 by lakkerma          #+#    #+#             */
/*   Updated: 2025/09/03 14:11:39 by lakkerma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

void	allocate_map_memory(t_game *game)
{
	int	y;

	game->map = malloc(sizeof(char *) * game->map_height);
	if (!game->map)
	{
		error_exit(game, "Error: malloc map height failed\n");
	}
	y = 0;
	while (y < game->map_height)
	{
		game->map[y] = malloc(sizeof(char) * (game->map_width + 1));
		if (!game->map[y])
		{
			error_exit(game, "Error: malloc map width failed\n");
		}
		ft_memset(game->map[y], ' ', game->map_width);
		y++;
	}
}
