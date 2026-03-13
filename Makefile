NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
SRC_HOOK = hooks
SRC_INIT = init
SRC_MAP = map
SRC_PLAYER = player
SRC_RENDER = render
SRC_MINIMAP = minimap
SRC_UTILS = utils
SRC_ENGINE = engine
SRC_RAYCAST = raycast
SRC_LOADER = loader
SRC = \
	$(SRC_DIR)/$(SRC_ENGINE)/$(SRC_RAYCAST)/raycast_cast.c \
	$(SRC_DIR)/$(SRC_ENGINE)/$(SRC_RAYCAST)/raycast_dda.c \
	$(SRC_DIR)/$(SRC_ENGINE)/$(SRC_RAYCAST)/raycast_init.c \
	$(SRC_DIR)/$(SRC_HOOK)/hooks.c \
	$(SRC_DIR)/$(SRC_INIT)/init.c \
	$(SRC_DIR)/$(SRC_LOADER)/loader.c \
	$(SRC_DIR)/$(SRC_MAP)/map_stub.c \
	$(SRC_DIR)/$(SRC_MAP)/map_query.c \
	$(SRC_DIR)/$(SRC_PLAYER)/player_move.c \
	$(SRC_DIR)/$(SRC_PLAYER)/player_update.c \
	$(SRC_DIR)/$(SRC_PLAYER)/player_rotate.c \
	$(SRC_DIR)/$(SRC_RENDER)/$(SRC_MINIMAP)/minimap_player_pos.c \
	$(SRC_DIR)/$(SRC_RENDER)/$(SRC_MINIMAP)/minimap_ray.c \
	$(SRC_DIR)/$(SRC_RENDER)/$(SRC_MINIMAP)/minimap_utils.c \
	$(SRC_DIR)/$(SRC_RENDER)/$(SRC_MINIMAP)/minimap.c \
	$(SRC_DIR)/$(SRC_RENDER)/render_scene.c \
	$(SRC_DIR)/$(SRC_RENDER)/render_walls.c \
	$(SRC_DIR)/$(SRC_RENDER)/render.c \
	$(SRC_DIR)/$(SRC_UTILS)/error.c \
	$(SRC_DIR)/$(SRC_UTILS)/exit.c \
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