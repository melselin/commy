cmake_minimum_required(VERSION 3.29)
project(libft C)

set(CMAKE_C_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_library(libft
		src/ft_isalpha.c
		src/ft_isdigit.c
		src/ft_isalnum.c
		src/ft_isprint.c
		src/ft_isascii.c
		src/ft_strlen.c
		src/ft_memset.c
)
