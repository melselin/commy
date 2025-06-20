NAME = push_swap

SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I . -I libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) libft/libft.a -o $(NAME)

clean:
	@make clean -C libft
	rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
