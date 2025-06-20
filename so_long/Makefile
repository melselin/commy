# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 14:02:29 by mwelfrin          #+#    #+#              #
#    Updated: 2025/01/02 14:02:40 by mwelfrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -lmlx
MLX_LIB_DIR = mlx
LIBFT = libft/libft.a
MLX = mlx/libmlx.a

X11_FLAGS = -lX11 -lXext

SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = libft mlx
INCLUDE_DIR = .

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -L$(MLX_LIB_DIR) $(MLX) $(MLX_FLAGS) $(X11_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -Imlx -Ilibft -c $< -o $@

$(LIBFT):
	@make -C libft

$(MLX):
	@make -C mlx
	
clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C libft
	@make clean -C mlx

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make clean -C mlx

re: fclean all
