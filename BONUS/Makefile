NAME = cub3D
CC = cc

# Detect OS (Darwin = macOS, otherwise assume Linux)
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	MLX_DIR = minilibx_opengl_20191021
	MLX_INC = -I$(MLX_DIR)
	MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit  -fsanitize=address
else
	# Linux
	MLX_DIR = $(HOME)/minilibx-linux
	MLX_INC = -I$(MLX_DIR)
	MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -lbsd
endif

CFLAGS = -Wall -Wextra -Werror -I. -Ilibft $(MLX_INC) 
LDFLAGS = $(MLX_LIB)

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

CFILES = $(shell find $(SRC_DIR) -name "*.c")
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(CFILES))

all: $(LIBFT_A) $(NAME)

$(MLX_DIR)/libmlx.a:
ifneq ($(UNAME_S),Darwin)
	@if [ -d "$(MLX_DIR)" ]; then \
		$(MAKE) -C $(MLX_DIR); \
	else \
		echo "MiniLibX directory $(MLX_DIR) not found"; exit 1; \
	fi
endif

$(NAME): $(OBJ) $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
