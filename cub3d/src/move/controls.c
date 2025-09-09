/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:30:35 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:30:37 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_game(game);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 1;
	if (keycode == KEY_A)
		game->keys.a = 1;
	if (keycode == KEY_S)
		game->keys.s = 1;
	if (keycode == KEY_D)
		game->keys.d = 1;
	if (keycode == KEY_LEFT)
		game->keys.left = 1;
	if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	if (keycode == KEY_SPACE)
		game->keys.space = 1;
	if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	if (keycode == KEY_A)
		game->keys.a = 0;
	if (keycode == KEY_S)
		game->keys.s = 0;
	if (keycode == KEY_D)
		game->keys.d = 0;
	if (keycode == KEY_LEFT)
		game->keys.left = 0;
	if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	if (keycode == KEY_SPACE)
		game->keys.space = 0;
	return (0);
}

int	mouse_hook(int mouse_x, int mouse_y, t_game *game)
{
	static int	previous_mouse_x = -1;
	int			delta_x;
	double		mouse_sensitivity;
	double		rotation_angle;

	(void)mouse_y;
	if (previous_mouse_x == -1)
		previous_mouse_x = mouse_x;
	delta_x = mouse_x - previous_mouse_x;
	previous_mouse_x = mouse_x;
	mouse_sensitivity = 0.003;
	rotation_angle = -delta_x * mouse_sensitivity;
	rotate_player(&game->player, rotation_angle);
	return (0);
}
