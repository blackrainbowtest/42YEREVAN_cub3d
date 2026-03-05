NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
SRC = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/hooks/hooks.c \
	$(SRC_DIR)/init/init.c \
	$(SRC_DIR)/map/map_stub.c \
	$(SRC_DIR)/map/map_query.c \
	$(SRC_DIR)/render/render.c \
	$(SRC_DIR)/render/minimap/minimap.c \
	$(SRC_DIR)/render/minimap/minimap_utils.c \
	$(SRC_DIR)/render/minimap/minimap_ray.c \
	$(SRC_DIR)/utils/error.c \
	$(SRC_DIR)/utils/exit.c

OBJ = $(SRC:.c=.o)

INCLUDES = -Iincludes -Iminilibx-linux

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

LIBFT_DIR = libraries/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all