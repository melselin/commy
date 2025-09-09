/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:33:46 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:33:48 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"
/* 
** Game loop: handle input, update world, and render frame 
*/
int	game_loop(t_game *game)
{
	if (game->keys.w)
		move_forward(game, &game->player.pos_x, &game->player.pos_y);
	if (game->keys.s)
		move_backward(game, &game->player.pos_x, &game->player.pos_y);
	if (game->keys.a)
		move_left(game, &game->player.pos_x, &game->player.pos_y);
	if (game->keys.d)
		move_right(game, &game->player.pos_x, &game->player.pos_y);
	if (game->keys.left)
		rotate_player(&game->player, -ROT_SPEED);
	if (game->keys.right)
		rotate_player(&game->player, ROT_SPEED);
	door_interaction(game);
	update_doors(game);
	update_enemies(game);
	render_frame(game);
	return (0);
}

/* 
** Render all drawing elements on the screen 
*/
int	render_frame(t_game *game)
{
	draw_background(game);
	raycast(game);
	render_sprites(game);
	draw_minimap(game);
	draw_hand(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img_ptr, 0, 0);
	draw_minimap_text(game, 8, 22);
	return (0);
}
