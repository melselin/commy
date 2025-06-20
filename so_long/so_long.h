/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:44:50 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/05 13:52:06 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC 65307
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_count;
	int		player_count;
	int		collectible_count;
	bool	**visited;
}			t_map;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

typedef struct s_direction
{
	int		dx;
	int		dy;
}			t_direction;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		dir;
}			t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*scores_img;
	void	*wall_img;
	void	*collectible_img;
	void	*exit_img;
	void	*empty_img;
	void	*floor_img;
	int		img_width;
	int		img_height;
	void	*player_frames[4][2];
	void	*enemy_frames[4][2];
	int		player_dir;
	int		enemy_dir;
	int		current_frame;
	int		frame_counter;
	t_map	map;
	int		moves;
	int		collected;
	int		game_over;
	bool	map_malloc;
}			t_game;

void		check_arg(int argc, char **argv, t_game *game);
int			close_window(t_game *game);
void		cleanup_images(t_game *game);
void		cleanup_game(t_game *game);
void		free_map(t_map *map);
void		draw_cell(t_game *game, char cell, int screen_x, int screen_y);
void		draw_map(t_game *game);
void		draw_player(t_game *game);
void		draw_moves(t_game *game);
void		draw_enemies(t_game *game);
int			enemy_collision(t_game *game);
void		set_enemy_direction(t_game *game, t_enemy *enemy);
void		move_enemy(t_game *game, t_enemy *enemy);
void		move_enemies(t_game *game);
int			init_game(t_game *game, const char *map_path);
int			handle_input(int keycode, t_game *game);
int			game_loop(t_game *game);
int			load_assets(t_game *game);
int			load_player_sprites(t_game *game);
int			load_enemy_sprites(t_game *game);
int			validate_sprites(t_game *game);
int			load_sprites(t_game *game);
int			start_load_map(t_game *game, const char *path);
int			read_map_lines(t_game *game, int fd);
int			validate_map_dimensions(t_game *game);
int			load_map(t_game *game, const char *path);
int			count_collectibles(t_game *game);
void		check_collectible(t_game *game, char next_cell);
void		calculate_new_pos(t_game *game, t_direction dir, int *new_x,
				int *new_y);
int			can_move(t_game *game, int new_x, int new_y);
void		scan_player(t_game *game);
void		update_player_direction(t_game *game, int dx, int dy);
void		check_game_over(t_game *game, char next_cell);
void		check_victory(t_game *game, char next_cell);
void		update_player_position(t_game *game, int new_x, int new_y);
void		move_player(t_game *game, int dx, int dy);
void		error_exit(const char *message, t_game *game);
int			validate_map_characters(t_game *game, t_map *map, int y, int x);
int			validate_map(t_map *map, t_game *game);
int			validate_exit(t_map *map, t_game *game);
int			count_lines(const char *path, t_game *game);
void		check_row(t_game *game);
void		check_column(t_game *game);
void		check_set_map(t_game *game);
void		check_parameters(t_game *game);
void		check_map(t_game *game);
void		check_empty_line(t_game *game, char *map);
int			start_load_map(t_game *game, const char *path);
int			read_map_lines(t_game *game, int fd);
int			validate_map_dimensions(t_game *game);
int			read_map_file(const char *path, t_game *game, char **map_tmp);
void		check_special_characters(t_game *game);
void		check_collectible_character(t_game *game, int x, int y);
void		check_exit_character(t_game *game, int x, int y);
void		check_player_character(t_game *game, int x, int y);
void		check_valid_characters(t_game *game);
void		cleaner(t_game *game);
void		validate_map_grid(t_map *map, t_game *game);
void		validate_map_chara(t_game *game, t_map *map, int y, int x);
void		read_and_copy(t_game *game, int fd, char **copy);
void		make_copy(t_game *game, char *path, char **copy);
void		flood_fill(t_game *game, char **copy, int x, int y);
void		duplication(t_game *game, char *path);
void		free_split(char **split);
void		free_split2(t_game *game, char **str);
void		allocate_visited(t_game *game);
void		initialize_visited(t_game *game);
void		check_unreachable(t_game *game);
void		free_visited(t_game *game);
void		free_map_grid(char **grid);

#endif
