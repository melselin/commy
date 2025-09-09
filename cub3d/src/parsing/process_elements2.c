/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_elements2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakkerma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:12:37 by lakkerma          #+#    #+#             */
/*   Updated: 2025/09/03 14:12:39 by lakkerma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

void	load_texture(t_game *game, t_texture *t, char *path)
{
	char	*trm_path;

	trm_path = ft_strtrim(path, " \n");
	t->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, trm_path, &t->width,
			&t->height);
	if (!t->img_ptr)
	{
		free(trm_path);
		error_exit(game, "Error: could not load texture\n");
	}
	t->data = mlx_get_data_addr(t->img_ptr, &t->bpp, &t->size_line, &t->endian);
	free(trm_path);
}

void	get_color(t_game *game, t_color *color, char *line)
{
	int		i;
	char	**rgb;

	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		error_exit(game, "Error: invalid color format\n");
	}
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
	{
		error_exit(game, "Error: color values must be between 0 and 255\n");
	}
	i = 0;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
}
