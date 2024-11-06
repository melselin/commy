# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 13:29:02 by mwelfrin          #+#    #+#              #
#    Updated: 2024/11/06 13:29:25 by mwelfrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs

SRC     = \
    ft_atoi.c \
    ft_bzero.c \
    ft_calloc.c \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_itoa.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_memcpy.c \
    ft_memmove.c \
    ft_memset.c \
    ft_putchar_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c \
    ft_putstr_fd.c \
    ft_split.c \
    ft_strchr.c \
    ft_strdup.c \
    ft_striteri.c \
    ft_strjoin.c \
    ft_strlcat.c \
    ft_strlcpy.c \
    ft_strlen.c \
    ft_strmapi.c \
    ft_strncmp.c \
    ft_strnstr.c \
    ft_strrchr.c \
    ft_strtrim.c \
    ft_substr.c \
    ft_tolower.c \
    ft_toupper.c

# Objeler
OBJ     = $(SRC:.c=.o)

# Derleme hedefi
all:    $(NAME)

# Arşiv (library) oluşturma
$(NAME): $(OBJ)
	$(AR) $@ $^

# Objeler için derleme kuralı
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Temizleme hedefi
clean:
	rm -f $(OBJ)

# Arşivi ve objeleri tamamen silme
fclean: clean
	rm -f $(NAME)

# Yeniden derleme
re: fclean all

# Paylaşımlı kütüphane oluşturma
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	$(CC) -nostartfiles -shared -o libft.so $(OBJ)

# Test için libft.a kütüphanesini bağlamak (link etmek)
test:
	clang++ -o ft_strnstr_test ft_strnstr_test.cpp -L. -lft

.PHONY: all clean fclean re so test
