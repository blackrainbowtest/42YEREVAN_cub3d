# Standard Makefile for MiniLibX project (42 school style)
NAME = cub3d
SRC = src/main.c
OBJ = $(SRC:.c=.o)
INCLUDES = -Iincludes -Iminilibx-linux

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
