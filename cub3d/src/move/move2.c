/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:31:07 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:31:09 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

/* 
** Check if a position (x, y) collides with any sprite
*/
static int	check_sprite_collision(t_game *game, double x, double y)
{
	int		i;
	double	dist;

	i = 0;
	while (i < game->sprite_count)
	{
		dist = sqrt((game->sprites[i].x - x) * (game->sprites[i].x - x)
				+ (game->sprites[i].y - y) * (game->sprites[i].y - y));
		if (dist < 0.3)
			return (1);
		i++;
	}
	return (0);
}

/* 
** Check if the player can move to a map tile at (x, y)
*/
static int	can_move_to(t_game *game, double x, double y)
{
	int		map_x;
	int		map_y;
	char	tile;
	t_door	*door;

	map_x = (int)x;
	map_y = (int)y;
	tile = game->map[map_y][map_x];
	if (tile == '0' || tile == 'N' || tile == 'S'
		|| tile == 'E' || tile == 'W' || tile == 'X')
		return (1);
	door = get_door(game, map_x, map_y);
	if (tile == 'D' && door && door->open_progress > 0.8)
		return (1);
	return (0);
}

/* 
** Move the player by the direction vector if no collision occurs
*/
void	move_player(t_game *game, t_move *move)
{
	double	new_x;
	double	new_y;

	new_x = *(move->new_x) + move->dir_x * MOVE_SPEED;
	new_y = *(move->new_y) + move->dir_y * MOVE_SPEED;
	if (check_sprite_collision(game, new_x, new_y))
		return ;
	if (can_move_to(game, new_x, *(move->new_y)))
		*(move->new_x) = new_x;
	if (can_move_to(game, *(move->new_x), new_y))
		*(move->new_y) = new_y;
}
