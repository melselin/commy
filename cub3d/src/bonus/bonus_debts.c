/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_debts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:23:10 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/01 14:25:15 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

static void	put_text_line(t_game *game, t_textline line)
{
	int	i;

	i = 0;
	while (line.str[i])
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr,
			line.x + i * (8 + 2),
			line.y,
			line.color,
			(char []){line.str[i], 0});
		i++;
	}
}

void	draw_minimap_text(t_game *game, int offset_x, int offset_y)
{
	static t_minimap_text	data = {
		.interest_rate = 1.0f,
		.debts = 0
	};

	data.interest_rate += 0.01f;
	data.debts += 1;
	snprintf(data.interest_str, sizeof(data.interest_str),
		"Interest Rate: %.2f%%", data.interest_rate);
	snprintf(data.debts_str, sizeof(data.debts_str),
		"Debts: %d bells", data.debts);
	data.interest_line.str = data.interest_str;
	data.interest_line.x = offset_x;
	data.interest_line.y = offset_y + 137;
	data.interest_line.color = 0xFFFF00;
	put_text_line(game, data.interest_line);
	data.debts_line.str = data.debts_str;
	data.debts_line.x = offset_x;
	data.debts_line.y = offset_y + 155;
	data.debts_line.color = 0xFFFF00;
	put_text_line(game, data.debts_line);
}
