CC = cc

NAME = cub3D

SRC_DIR = src
MAIN_DIR = $(SRC_DIR)/main
MOVE_DIR = $(SRC_DIR)/move
PARSE_DIR = $(SRC_DIR)/parsing
RAYCAST_DIR = $(SRC_DIR)/raycast
RENDER_DIR = $(SRC_DIR)/render
UTILS_DIR = $(SRC_DIR)/utils
BONUS_DIR = $(SRC_DIR)/bonus

OBJ_DIR = obj
MAIN_OBJ_DIR = $(OBJ_DIR)/main
MOVE_OBJ_DIR = $(OBJ_DIR)/move
PARSE_OBJ_DIR = $(OBJ_DIR)/parsing
RAYCAST_OBJ_DIR = $(OBJ_DIR)/raycast
RENDER_OBJ_DIR = $(OBJ_DIR)/render
UTILS_OBJ_DIR = $(OBJ_DIR)/utils
BONUS_OBJ_DIR = $(OBJ_DIR)/bonus

MAIN_SRC_FILES = main.c arg_check.c
MOVE_SRC_FILES = move.c move2.c controls.c move_door.c
PARSE_SRC_FILES = read_map.c parse_map.c process_elements.c process_elements2.c process_map.c \
				read_map2.c parse_map2.c validate_map.c validate_player.c validate_horizontal.c validate_vertical.c map_malloc.c
RAYCAST_SRC_FILES = raycast.c raycast_dda.c raycast_init.c raycast_render.c
RENDER_SRC_FILES = render.c background.c hand.c door.c
UTILS_SRC_FILES = utils.c
BONUS_SRC_FILES = bonus_enemy.c bonus_parsing.c bonus_collision.c bonus_sprites.c bonus_sprites2.c bonus_minimap.c bonus_minimap2.c bonus_debts.c

SRC = 	$(addprefix $(MAIN_DIR)/, $(MAIN_SRC_FILES)) \
	   	$(addprefix $(MOVE_DIR)/, $(MOVE_SRC_FILES)) \
	   	$(addprefix $(PARSE_DIR)/, $(PARSE_SRC_FILES)) \
	   	$(addprefix $(RAYCAST_DIR)/, $(RAYCAST_SRC_FILES)) \
	   	$(addprefix $(RENDER_DIR)/, $(RENDER_SRC_FILES)) \
	   	$(addprefix $(UTILS_DIR)/, $(UTILS_SRC_FILES)) \
	   	$(addprefix $(BONUS_DIR)/, $(BONUS_SRC_FILES))
OBJ = 	$(addprefix $(MAIN_OBJ_DIR)/, $(MAIN_SRC_FILES:.c=.o)) \
	   	$(addprefix $(MOVE_OBJ_DIR)/, $(MOVE_SRC_FILES:.c=.o)) \
	   	$(addprefix $(PARSE_OBJ_DIR)/, $(PARSE_SRC_FILES:.c=.o)) \
	   	$(addprefix $(RAYCAST_OBJ_DIR)/, $(RAYCAST_SRC_FILES:.c=.o)) \
	   	$(addprefix $(RENDER_OBJ_DIR)/, $(RENDER_SRC_FILES:.c=.o)) \
	   	$(addprefix $(UTILS_OBJ_DIR)/, $(UTILS_SRC_FILES:.c=.o)) \
	   	$(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_SRC_FILES:.c=.o))

LIBFT_DIR = ./libft
PRINTF_DIR = ./libft/ft_printf
MLX_DIR = ./mlx
INCLUDE = -I./include -I$(LIBFT_DIR) -I$(MLX_DIR)

CFLAGS = -Wall -Wextra -Werror $(INCLUDE) -g
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
PRINTF_FLAGS = -L$(PRINTF_DIR) -lftprintf
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(NAME)

$(NAME): 	$(OBJ)
			$(MAKE) -C $(LIBFT_DIR)
			$(MAKE) -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) $(PRINTF_FLAGS) $(MLX_FLAGS) -lm -o $(NAME)

$(MAIN_OBJ_DIR)/%.o: $(MAIN_DIR)/%.c
	@mkdir -p $(MAIN_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MOVE_OBJ_DIR)/%.o: $(MOVE_DIR)/%.c
	@mkdir -p $(MOVE_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(PARSE_OBJ_DIR)/%.o: $(PARSE_DIR)/%.c
	@mkdir -p $(PARSE_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(RAYCAST_OBJ_DIR)/%.o: $(RAYCAST_DIR)/%.c
	@mkdir -p $(RAYCAST_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(RENDER_OBJ_DIR)/%.o: $(RENDER_DIR)/%.c
	@mkdir -p $(RENDER_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(UTILS_OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(UTILS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
