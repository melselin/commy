NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
      ft_putchar.c \
      ft_putstr.c \
      ft_putnbr.c \
      ft_putunbr.c \
      ft_puthex.c \
      ft_putptr.c \
      ft_strlen.c

# Obje dosyaları
OBJ = $(SRC:.c=.o)

# Varsayılan hedef: Kütüphaneyi oluştur
all: $(NAME)

# Kütüphaneyi oluşturmak için ar komutunu kullanıyoruz
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Obje dosyalarını derlemek için kullanılan kural
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

# Temizlik işlemi: obj dosyalarını sil
clean:
	rm -f $(OBJ)

# Temizlik ve yeniden derleme işlemi
fclean: clean
	rm -f $(NAME)

# Temizlik yap ve kütüphaneyi yeniden oluştur
re: fclean all

# .PHONY hedefleri: 'make clean', 'make fclean', 'make re' komutlarının
# dosya değil, hedef olduğunu belirtmek için kullanılır
.PHONY: all clean fclean re
