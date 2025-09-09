/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_sprites2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:24:23 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:24:26 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"
/*
** Calculate sprite position relative to player (transform space)
*/
void	calc_sprite_transform(t_game *game, t_sprite *sprite, t_transform *tr)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	if (!game || !sprite || !tr)
		return ;
	sprite_x = sprite->x - game->player.pos_x;
	sprite_y = sprite->y - game->player.pos_y;
	inv_det = game->player.plane_x * game->player.dir_y
		- game->player.dir_x * game->player.plane_y;
	if (inv_det == 0)
	{
		tr->x = 0;
		tr->y = 1;
		tr->screen_x = WIN_WIDTH / 2;
		return ;
	}
	inv_det = 1.0 / inv_det;
	tr->x = inv_det * (game->player.dir_y * sprite_x
			- game->player.dir_x * sprite_y);
	tr->y = inv_det * (-game->player.plane_y * sprite_x
			+ game->player.plane_x * sprite_y);
	if (tr->y == 0)
		tr->y = 1;
	tr->screen_x = (int)((WIN_WIDTH / 2) * (1 + tr->x / tr->y));
}

/*
** Calculate screen bounds for sprite rendering
*/
void	calc_sprite_bounds(t_transform *tr, t_bounds *b)
{
	b->height = abs((int)(WIN_HEIGHT / tr->y));
	b->start_y = -b->height / 2 + WIN_HEIGHT / 2;
	if (b->start_y < 0)
		b->start_y = 0;
	b->end_y = b->height / 2 + WIN_HEIGHT / 2;
	if (b->end_y >= WIN_HEIGHT)
		b->end_y = WIN_HEIGHT - 1;
	b->width = abs((int)(WIN_HEIGHT / tr->y));
	b->start_x = -b->width / 2 + tr->screen_x;
	if (b->start_x < 0)
		b->start_x = 0;
	b->end_x = b->width / 2 + tr->screen_x;
	if (b->end_x >= WIN_WIDTH)
		b->end_x = WIN_WIDTH - 1;
}

/*
** Load all sprite-related textures
*/
void	bonus_load_text(t_game *game)
{
	load_texture(game, &game->sprite_tex, "./assets/nook.xpm");
	load_texture(game, &game->hand_tex, "./assets/hands.xpm");
	load_texture(game, &game->idle_tex, "./assets/idle.xpm");
	load_texture(game, &game->enemy_tex, "./assets/nook2.xpm");
}
