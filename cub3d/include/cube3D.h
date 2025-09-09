/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:38:54 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/09/09 13:27:48 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

/****************************************************************************\
* ✿  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆  EXTERNAL AND LOCAL LIBRARIES  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆ ✿
\****************************************************************************/

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/****************************************************************************\
* ✿  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆  WINDOW CONSTANTS  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆              ✿
\****************************************************************************/

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

/****************************************************************************\
* ✿  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆  MOVEMENT CONSTANTS  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆            ✿
\****************************************************************************/

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

/*****************************************************************************\
* ✿  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆  KEY CODES  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆                     ✿
\*****************************************************************************/

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define KEY_SPACE 32

/*****************************************************************************\
* ✿  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆  MINIMAP CONSTANTS  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆              ✿
\*****************************************************************************/

# define MAX_LINES 100
# define MINIMAP_CELL_SIZE 10
# define MINIMAP_RADIUS 60
# define MINIMAP_CENTER_X 80
# define MINIMAP_CENTER_Y 80

/*****************************************************************************\
* ✿  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆  DATA STRUCTURES  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆                ✿
\*****************************************************************************/
typedef struct s_game	t_game;
void					free_map_data(t_game *game);

typedef struct s_textline
{
	char				*str;
	int					x;
	int					y;
	int					color;
}						t_textline;

typedef struct s_minimap_text
{
	float				interest_rate;
	int					debts;
	char				interest_str[64];
	char				debts_str[64];
	t_textline			interest_line;
	t_textline			debts_line;
}						t_minimap_text;

typedef struct s_hand_draw
{
	float				scale;
	int					scaled_width;
	int					scaled_height;
	int					start_x;
	int					start_y;
	int					y;
	int					x;
}						t_hand_draw;

typedef struct s_hand_pixel
{
	int					x;
	int					y;
	float				scale;
	int					start_x;
	int					start_y;
}						t_hand_pixel;

typedef struct s_move
{
	double				*new_x;
	double				*new_y;
	double				dir_x;
	double				dir_y;
}						t_move;

typedef struct s_transform
{
	double				x;
	double				y;
	int					screen_x;
}						t_transform;

typedef struct s_bounds
{
	int					height;
	int					width;
	int					start_x;
	int					end_x;
	int					start_y;
	int					end_y;
}						t_bounds;

typedef struct s_keys
{
	int					w;
	int					a;
	int					s;
	int					d;
	int					left;
	int					right;
	int					space;
}						t_keys;

typedef struct s_color
{
	int					r;
	int					g;
	int					b;
	int					flag;
}						t_color;

typedef struct s_texture
{
	void				*img_ptr;
	void				*data;
	int					width;
	int					height;
	int					flag;
	int					size_line;
	int					bpp;
	int					endian;
}						t_texture;

typedef struct s_line
{
	int					start_x;
	int					end_x;
	int					y;
	int					color;
}						t_line;

typedef struct s_ray_dir
{
	double				x;
	double				y;
}						t_ray_dir;

typedef struct s_map_pos
{
	int					x;
	int					y;
}						t_map_pos;

typedef struct s_step_side
{
	int					step_x;
	int					step_y;
	double				side_dist_x;
	double				side_dist_y;
}						t_step_side;

typedef struct s_delta_dist
{
	double				x;
	double				y;
}						t_delta_dist;

typedef struct s_player
{
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
}						t_player;

typedef struct s_sprite
{
	double				x;
	double				y;
	t_texture			tex;
	int					visible;
	double				angle;
}						t_sprite;

typedef struct s_sprite_col
{
	t_texture			*tex;
	t_transform			*tr;
	t_bounds			*b;
	int					x;
}						t_sprite_col;

typedef struct s_enemy_update
{
	int					i;
	double				dx;
	double				dy;
	double				len;
	int					moved;
}						t_enemy_update;

typedef struct s_door
{
	int					x;
	int					y;
	bool				open;
	double				open_progress;
	int					is_opening;
	int					is_closing;
}						t_door;

typedef struct s_game
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*img_data;
	int					img_line;
	int					pixel_bits;
	int					pixel_endian;
	char				**map;
	int					map_width;
	int					map_height;
	t_texture			sprite_tex;
	t_texture			hand_tex;
	t_texture			enemy_tex;
	t_texture			idle_tex;
	t_texture			door_tex;
	t_texture			no;
	t_texture			so;
	t_texture			we;
	t_texture			ea;
	t_color				floor;
	t_color				ceiling;
	t_player			player;
	t_sprite			*sprites;
	t_door				*doors;
	t_keys				keys;
	int					sprite_count;
	int					total_sprites;
	int					door_count;
	double				*z_buffer;
}						t_game;

typedef struct s_map_state
{
	int					map_start;
	int					*map_flag;
	int					in_map;
	int					line_count;
}						t_map_state;

typedef struct s_parse_result
{
	char				**lines;
	int					line_count;
	int					map_flag;
}						t_parse_result;

typedef struct s_read_context
{
	int					fd;
	char				**lines;
	int					line_count;
	char				*buffer;
}						t_read_context;

typedef struct s_line_processor
{
	t_game				*game;
	int					fd;
	char				**lines;
	int					*line_count;
	t_map_state			*state;
	t_read_context		*ctx;
}						t_line_processor;

typedef struct s_raycast_init
{
	t_game				*game;
	t_ray_dir			ray_dir;
	t_map_pos			map_pos;
	t_delta_dist		delta_dist;
}						t_raycast_init;

typedef struct s_dda_data
{
	t_game				*game;
	t_ray_dir			*ray_dir;
	t_map_pos			*map_pos;
	t_step_side			*step_side;
	t_delta_dist		*delta_dist;
}						t_dda_data;

typedef struct s_dda_result
{
	int					hit;
	int					side;
	int					is_door;
	t_door				*hit_door;
}						t_dda_result;

typedef struct s_minimap_draw
{
	t_game				*game;
	int					map_x;
	int					map_y;
	int					screen_x;
	int					screen_y;
}						t_minimap_draw;

typedef struct s_minimap_pixel
{
	int					px;
	int					py;
	int					dx;
	int					dy;
	int					color;
}						t_minimap_pixel;

typedef struct s_minimap_border
{
	int					x;
	int					y;
	int					dx;
	int					dy;
	int					dist_sq;
}						t_minimap_border;

typedef struct s_circle_check
{
	int					x;
	int					y;
	int					center_x;
	int					center_y;
	int					radius;
}						t_circle_check;

typedef struct s_column_draw
{
	int					x;
	int					draw_start;
	int					draw_end;
	int					line_height;
}						t_column_draw;

typedef struct s_ray_result
{
	int					side;
	double				perp_wall_dist;
	double				ray_dir_x;
	double				ray_dir_y;
}						t_ray_result;

typedef struct s_draw_vars
{
	double				step;
	double				tex_pos;
	int					tex_x;
	int					tex_y;
	int					color;
	int					y;
}						t_draw_vars;

typedef struct s_raycast_vars
{
	int					x;
	double				camera_x;
	t_ray_dir			ray_dir;
	t_map_pos			map_pos;
	t_step_side			step_side;
}						t_raycast_vars;

typedef struct s_wall_calc
{
	t_delta_dist		delta_dist;
	double				perp_wall_dist;
	int					side;
	int					is_door;
	t_door				*hit_door;
}						t_wall_calc;

typedef struct s_render_data
{
	t_texture			*tex;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				wall_x;
}						t_render_data;

/*****************************************************************************\
* ✿  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆  FUNCTION DECLARATIONS  ☆*: .｡. ✿♥‿♥✿ .｡.:*☆         ✿
\*****************************************************************************/

/* main / args */
bool					arg_check(char *filename);

/* parsing */
void					parse_map(t_game *game, char *file);
void					process_map_data(t_game *game, char **lines,
							int line_count, int map_flag);
void					parse_map_file(t_game *game, char *file,
							t_parse_result *result);
void					load_texture(t_game *game, t_texture *t, char *path);
void					get_color(t_game *game, t_color *color, char *line);
void					process_text_col(t_game *game, char **lines,
							int line_count, int map_flag);
void					process_map(t_game *game, char **lines, int line_count,
							int map_flag);
char					**read_map(t_game *game, int fd, int *line_count,
							int *map_flag);
void					process_map_lines(t_line_processor *processor);
void					process_line_full(t_game *game, char *line,
							t_map_state *state, t_read_context *ctx);
void					check_elements_after_map(t_game *game, char *line,
							t_map_state *state, t_read_context *ctx);
void					process_map_content(t_game *game, char *line,
							t_map_state *state, t_read_context *ctx);
void					cleanup_and_exit(t_game *game, t_read_context *ctx,
							char *line, char *error_msg);
void					check_empty_line_map(t_game *game, int fd);
int						is_map_content(char *line);
void					init_map_state(t_map_state *state, int *flag);
void					validate_player_count(t_game *game, char **lines,
							int line_count, int map_flag);
void					validate_map(t_game *game);
void					allocate_map_memory(t_game *game);
int						is_element_line(char *line);
int						validate_line_cells(t_game *game, int x);
int						validate_row_cells(t_game *game, int y);
int						additional_checks_y(t_game *game, int x);
int						additional_checks_x(t_game *game, int y);

/* move & input */
int						close_window(void *param);
int						key_press(int keycode, t_game *game);
int						key_release(int keycode, t_game *game);
int						mouse_hook(int mouse_x, int mouse_y, t_game *game);
void					move_player(t_game *game, t_move *move);
void					move_forward(t_game *game, double *new_x,
							double *new_y);
void					move_backward(t_game *game, double *new_x,
							double *new_y);
void					move_left(t_game *game, double *new_x, double *new_y);
void					move_right(t_game *game, double *new_x, double *new_y);
void					rotate_player(t_player *player, double angle);
t_door					*get_door(t_game *game, int x, int y);

/* raycast */
void					raycast(t_game *game);
void					init_raycast_vars(t_raycast_vars *vars, t_game *game,
							int x);
void					perform_wall_calculation(t_game *game,
							t_raycast_vars *vars, t_wall_calc *wall_calc);
void					calculate_wall_distance(t_game *game,
							t_raycast_vars *vars, t_wall_calc *wall_calc);
void					calculate_render_data(t_game *game,
							t_raycast_vars *vars, t_wall_calc *wall_calc,
							t_render_data *render);
void					render_wall_column(t_game *game, t_raycast_vars *vars,
							t_render_data *render, t_wall_calc *wall_calc);
void					init_step_side(t_raycast_init *init_data,
							t_step_side *step_side);
t_dda_result			perform_dda_algorithm(t_dda_data *dda_data);
void					advance_dda(t_dda_data *dda_data, t_dda_result *result);
int						check_hit_or_door(t_dda_data *dda_data,
							t_dda_result *result);
void					check_door_hit(t_dda_data *dda_data,
							t_dda_result *result);
int						perform_dda(t_game *game, int *map_x, int *map_y,
							int *side);

/* render */
int						game_loop(t_game *game);
int						render_frame(t_game *game);
void					draw_line(t_game *game, t_line line);
void					draw_background(t_game *game);
void					draw_column(t_game *game, t_texture *tex,
							t_column_draw *col_draw, t_ray_result *ray_result);
void					render_sprites(t_game *game);
void					draw_hand(t_game *game);
void					calc_sprite_transform(t_game *game, t_sprite *sprite,
							t_transform *tr);
void					calc_sprite_bounds(t_transform *tr, t_bounds *b);
void					draw_sprite(t_game *game, t_texture *tex,
							t_transform *tr, t_bounds *b);
void					door_interaction(t_game *game);
void					update_doors(t_game *game);

/* utils */
void					error_exit(t_game *game, char *msg);
void					free_game(t_game *game);
void					free_lines_array(char **lines, int line_count);

// * ❃    BONUS    ❃ *
void					bonus_count_store_sprites(t_game *game, char *line);
void					bonus_count_doors(t_game *game, char *line);
void					bonus_mem_sprite(t_game *game);
void					bonus_mem_doors(t_game *game);
void					bonus_sprite_pos(t_game *game, int x, int y);
void					bonus_load_text(t_game *game);
void					update_enemies(t_game *game);
void					check_enemy_collision(t_sprite *a, t_sprite *b);
void					draw_minimap(t_game *game);
void					draw_minimap_text(t_game *game, int offset_x,
							int offset_y);
int						is_wall(t_game *game, double x, double y);
int						is_enemy_collision(t_game *game, int idx, double x,
							double y);
void					draw_focused_minimap_cells(t_game *game);
void					draw_minimap_border(t_game *game);
void					draw_border_pixel(t_game *game, int x, int y);
void					draw_focused_player(t_game *game, int screen_x,
							int screen_y);
void					draw_focused_cell(t_minimap_draw *params);
void					draw_minimap_pixel(t_game *game,
							t_minimap_pixel *pixel);
int						is_in_circle(t_circle_check *circle);

#endif /* CUBE3D_H */
