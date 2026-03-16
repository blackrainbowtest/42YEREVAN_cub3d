NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR      = src

ENGINE_DIR   = $(SRC_DIR)/engine
RAYCAST_DIR  = $(ENGINE_DIR)/raycast

HOOK_DIR     = $(SRC_DIR)/hooks
INIT_DIR     = $(SRC_DIR)/init
MAP_DIR      = $(SRC_DIR)/map
PLAYER_DIR   = $(SRC_DIR)/player

RENDER_DIR   = $(SRC_DIR)/render
MINIMAP_DIR  = $(RENDER_DIR)/minimap

UTILS_DIR    = $(SRC_DIR)/utils
LOADER_DIR   = $(SRC_DIR)/loader

SRC = \
	$(RAYCAST_DIR)/raycast_cast.c \
	$(RAYCAST_DIR)/raycast_dda.c \
	$(RAYCAST_DIR)/raycast_init.c \
	$(HOOK_DIR)/hooks.c \
	$(INIT_DIR)/init.c \
	$(LOADER_DIR)/loader.c \
	$(MAP_DIR)/map_stub.c \
	$(MAP_DIR)/map_query.c \
	$(PLAYER_DIR)/player_move.c \
	$(PLAYER_DIR)/player_update.c \
	$(PLAYER_DIR)/player_rotate.c \
	$(MINIMAP_DIR)/minimap_player_pos.c \
	$(MINIMAP_DIR)/minimap_ray.c \
	$(MINIMAP_DIR)/minimap_utils.c \
	$(MINIMAP_DIR)/minimap_line.c \
	$(MINIMAP_DIR)/minimap.c \
	$(RENDER_DIR)/render_scene.c \
	$(RENDER_DIR)/render_walls.c \
	$(RENDER_DIR)/render.c \
	$(UTILS_DIR)/error.c \
	$(UTILS_DIR)/exit.c \
	$(SRC_DIR)/main.c

OBJ = $(SRC:.c=.o)
HEADER = includes/cub3d.h

INCLUDES = -Iincludes -Iminilibx-linux

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

LIBFT_DIR = libraries/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all