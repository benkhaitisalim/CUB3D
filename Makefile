NAME_MANDATORY = cub3D
NAME_BONUS = cub3D_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

FOLDER_MLX = minilibx_opengl_20191021
MLX = -L$(FOLDER_MLX) -I$(FOLDER_MLX) -lmlx -framework OpenGL -framework AppKit
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MANDATORY_SRC = mandatory/src
BONUS_SRC = BONUS/src

MANDATORY_FILES = \
	color_parse.c coord.c draw.c free.c hooks.c init_structs.c main.c mlx_setup.c moves.c \
	parse_map.c parse_text.c parse_utils.c parse_utils2.c parse_utils3.c recasting.c \
	setups.c split.c split_nbr.c texture.c validate_map.c validate_map1.c \
	validate_map2.c validate_map3.c \
	helper_function/get_next_line.c helper_function/get_next_line_utils.c \
	helper_function/my_split.c helper_function/utils.c texture_2.c \

BONUS_FILES = \
	color_parse.c coord.c door_texture.c doors.c draw.c free.c gun.c hooks.c \
	init_structs.c main.c mini_map.c mlx_setup.c moves.c parse_doors.c parse_map.c \
	parse_text.c parse_utils.c parse_utils2.c parse_utils3.c recasting.c setups.c \
	split.c split_nbr.c texture.c texture2.c validate_map.c validate_map1.c \
	validate_map2.c validate_map3.c \
	helper_function/get_next_line.c helper_function/get_next_line_utils.c \
	helper_function/my_split.c helper_function/utils.c texture_2.c 
OBJ_DIR = obj
MANDATORY_OBJS = $(addprefix $(MANDATORY_SRC)/, $(MANDATORY_FILES))
BONUS_OBJS = $(addprefix $(BONUS_SRC)/, $(BONUS_FILES))

all: $(NAME_MANDATORY)

bonus: $(NAME_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME_MANDATORY): $(MANDATORY_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(MLX) $(LIBFT) -o $@

$(NAME_BONUS): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(MLX) $(LIBFT) -o $@

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME_MANDATORY) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
