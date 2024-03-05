NAME = so_long
NAME_BONUS= so_long_bonus
# INCFLAGS = -DEBUG=1 -Iinclude -lglfw -L /opt/homebrew/Cellar/glfw/3.3.6/lib/
ifeq ($(shell uname), Darwin)
	INCFLAGS = -DEBUG=1 -Iinclude -lglfw -L"/Users/alfofern/.brew/Cellar/glfw/3.3.8/lib"
else
	INCFLAGS = -ldl -DEBUG=1 -Iinclude -lglfw -L"usr/lib/x86_64-linux-gnu/"
endif

SRC =	src/main.c \
		src/utils.c \
		src/checkmap_content.c \
		src/checkmapfile_and_path.c \
		src/drawgame.c \
		src/movements.c \
		src/updategame.c
		
#SRC_BONUS	= 

OBJT = $(SRC:.c=.o)

#OBJ_BONUS	= $(SRC_BONUS:.c=.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX42_DIR = ./MLX42

MLX42 = $(MLX42_DIR)/libmlx42.a

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

MAKEFLAGS += --quiet

all: $(LIBFT) $(MLX42) $(NAME)

$(NAME): $(OBJT)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIBFT) $(MLX42) $(INCFLAGS)

#$(NAME_BONUS): $(OBJ_BONUS)

#	@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) $(MLX42) $(INCFLAGS) -o $(NAME_BONUS)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(MLX42):
		$(MAKE) -C $(MLX42_DIR)

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(MLX42_DIR) 
		$(RM) $(OBJT) $(OBJ_BONUS)

fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		$(MAKE) fclean -C $(MLX42_DIR)
		$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
	$(MAKE) clean

.PHONY: all clean fclean re
