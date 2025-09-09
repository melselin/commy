/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:33:39 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:33:40 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

/*
** Put a single pixel of the hand texture on the screen with scaling and bounds
*/
static void	put_hand_pixel(t_game *game, t_texture *tex, t_hand_pixel *hp)
{
	int				orig_x;
	int				orig_y;
	unsigned int	tex_color;
	int				screen_x;
	int				screen_y;

	orig_x = (int)(hp->x / hp->scale);
	orig_y = (int)(hp->y / hp->scale);
	tex_color = *(unsigned int *)(tex->data + orig_y * tex->size_line + orig_x
			* (tex->bpp / 8));
	if (tex_color != 0 && tex_color != 0xFF000000)
	{
		screen_x = hp->start_x + hp->x;
		screen_y = hp->start_y + hp->y;
		if (screen_x >= 0 && screen_x < WIN_WIDTH && screen_y >= 0
			&& screen_y < WIN_HEIGHT)
			*(int *)(game->img_data + screen_y * game->img_line + screen_x
					* (game->pixel_bits / 8)) = tex_color;
	}
}

/* 
** (I mean thanks norminette)
** Draw a single horizontal line of the hand texture on the screen
*/
static void	draw_hand_line(t_game *game, t_texture *tex, t_hand_draw *hd, int y)
{
	t_hand_pixel	hp;
	int				x;

	x = 0;
	while (x < hd->scaled_width)
	{
		hp.x = x;
		hp.y = y;
		hp.scale = hd->scale;
		hp.start_x = hd->start_x;
		hp.start_y = hd->start_y;
		put_hand_pixel(game, tex, &hp);
		x++;
	}
}

/* 
** Draw the hand on the screen by scaling the texture to the window width
*/
void	draw_hand(t_game *game)
{
	t_texture		*tex;
	t_hand_draw		hd;
	int				y;

	tex = &game->hand_tex;
	hd.scale = (float)WIN_WIDTH / (float)tex->width;
	hd.scaled_width = WIN_WIDTH;
	hd.scaled_height = (int)(tex->height * hd.scale);
	hd.start_x = 0;
	hd.start_y = WIN_HEIGHT - hd.scaled_height;
	y = 0;
	while (y < hd.scaled_height)
	{
		draw_hand_line(game, tex, &hd, y);
		y++;
	}
}
