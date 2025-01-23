# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 09:07:04 by mwelfrin          #+#    #+#              #
#    Updated: 2025/01/23 09:07:07 by mwelfrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a


all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(LIBFT)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(LIBFT)

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
