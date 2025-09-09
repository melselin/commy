/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:38:10 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/07 13:27:38 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3D.h"

/*
** Print error message, free resources and exit
*/
void	error_exit(t_game *game, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free_game(game);
	exit(1);
}

/*
** Free map memory
*/
void	free_map_data(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

/*
** Free textures and image resources
*/
static void	free_textures(t_game *game)
{
	if (game->no.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->no.img_ptr);
	if (game->so.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->so.img_ptr);
	if (game->we.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->we.img_ptr);
	if (game->ea.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->ea.img_ptr);
	if (game->sprite_tex.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->sprite_tex.img_ptr);
	if (game->hand_tex.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->hand_tex.img_ptr);
	if (game->idle_tex.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->idle_tex.img_ptr);
	if (game->enemy_tex.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->enemy_tex.img_ptr);
	if (game->door_tex.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->door_tex.img_ptr);
}

/*
** Free all allocated memory and destroy MLX resources
*/
void	free_game(t_game *game)
{
	free_map_data(game);
	free_textures(game);
	if (game->sprites)
		free(game->sprites);
	if (game->doors)
		free(game->doors);
	if (game->z_buffer)
		free(game->z_buffer);
	if (game->img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->img_ptr);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free_all_gnl_buffers();
}

void	free_lines_array(char **lines, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}
