/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:24:09 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:24:13 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"
/*
** Main sprite rendering function
*/
void	render_sprites(t_game *game)
{
	int			i;
	t_transform	tr;
	t_bounds	b;

	if (!game || !game->sprites || !game->z_buffer || !game->img_data)
		return ;
	i = 0;
	while (i < game->sprite_count)
	{
		calc_sprite_transform(game, &game->sprites[i], &tr);
		calc_sprite_bounds(&tr, &b);
		draw_sprite(game, &game->sprites[i].tex, &tr, &b);
		i++;
	}
}

/*
** Draw sprite without texture (fallback = red block)
*/
static void	draw_sprite_no_tex(t_game *game, t_transform *tr, t_bounds *b)
{
	int	x;
	int	y;

	x = b->start_x;
	while (x < b->end_x)
	{
		if (tr->y > 0 && x >= 0 && x < WIN_WIDTH && tr->y < game->z_buffer[x])
		{
			y = b->start_y;
			while (y < b->end_y)
			{
				*(int *)(game->img_data + y * game->img_line + x
						* (game->pixel_bits / 8)) = 0xFF0000;
				y++;
			}
		}
		x++;
	}
}

/*
** Draw a single column of the sprite
*/
static void	draw_sprite_column(t_game *game, t_sprite_col *col)
{
	int				y;
	int				tex_x;
	int				tex_y;
	unsigned int	color;

	tex_x = (int)(256 * (col->x - (-col->b->width / 2 + col->tr->screen_x))
			* col->tex->width / col->b->width) / 256;
	if (col->tr->y <= 0 || col->x < 0 || col->x >= WIN_WIDTH
		|| col->tr->y >= game->z_buffer[col->x])
		return ;
	y = col->b->start_y;
	while (y < col->b->end_y)
	{
		tex_y = (int)(((y - (-col->b->height / 2 + WIN_HEIGHT / 2)) * 256
					* col->tex->height) / col->b->height) / 256;
		color = *(unsigned int *)(col->tex->data + tex_y * col->tex->size_line
				+ tex_x * (col->tex->bpp / 8));
		if (color != 0 && color != 0xFF000000 && color != 0x00000000)
			*(int *)(game->img_data + y * game->img_line + col->x
					* (game->pixel_bits / 8)) = color;
		y++;
	}
}

/*
** Draw sprite with texture mapping
*/
void	draw_sprite_tex(t_game *game, t_texture *tex, t_transform *tr,
		t_bounds *b)
{
	int				x;
	t_sprite_col	col;

	x = b->start_x;
	while (x < b->end_x)
	{
		col.tex = tex;
		col.tr = tr;
		col.b = b;
		col.x = x;
		draw_sprite_column(game, &col);
		x++;
	}
}

/*
** Main sprite drawing function
*/
void	draw_sprite(t_game *game, t_texture *tex, t_transform *tr, t_bounds *b)
{
	if (!game || !tex || !tr || !b || !game->img_data || !game->z_buffer)
		return ;
	if (!tex->data)
		draw_sprite_no_tex(game, tr, b);
	else
		draw_sprite_tex(game, tex, tr, b);
}
