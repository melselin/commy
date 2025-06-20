# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 11:24:31 by mwelfrin          #+#    #+#              #
#    Updated: 2024/11/07 11:24:38 by mwelfrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program adı ve derleme ayarları
NAME    = libft.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs

# Kaynak dosyalar
SRC     = \
    ft_atoi.c \
    ft_atol.c \
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
    ft_toupper.c \
    get_next_line.c \
    get_next_line_utils.c \
    ft_printf.c \
    ft_putchar.c \
    ft_putstr.c \
    ft_putnbr.c \
    ft_putunbr.c \
    ft_puthex.c \
    ft_putptr.c

# Objelerin oluşturulacağı dosyalar
OBJ	= $(SRC:.c=.o)

# Varsayılan hedef
all: $(NAME)

# Kütüphane oluşturma
$(NAME): $(OBJ)
	$(AR) $@ $^

# .c dosyalarını .o dosyalarına derleme kuralı
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Objeleri temizleme
clean:
	rm -f $(OBJ)

# Kütüphaneyi ve objeleri tamamen temizleme
fclean: clean
	rm -f $(NAME)

# Temizleme ve yeniden derleme
re: fclean all

# .PHONY kuralları, belirli hedeflerin dosya isimleriyle çakışmasını önler
.PHONY: all clean fclean re

