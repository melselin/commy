/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:31:15 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:31:17 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

t_door	*get_door(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->door_count)
	{
		if (game->doors[i].x == x && game->doors[i].y == y)
			return (&game->doors[i]);
		i++;
	}
	return (NULL);
}
