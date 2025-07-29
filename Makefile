NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -fsanitize=leak

MLX42_PATH = ./MLX42
LIBFT_PATH = ./libft
MLX42_REPO = https://github.com/codam-coding-college/MLX42.git
MLX42_VERSION = ce254c3

HEADERS = -I$(MLX42_PATH)/include -I$(LIBFT_PATH)
LIBS = $(MLX42_PATH)/build/libmlx42.a $(LIBFT_PATH)/libft.a -ldl -lglfw -pthread -lm

SRC_DIR = src/
OBJ_DIR = obj/
SRCS = main.c complex_stuff.c events.c fractals.c pixel_colors.c utils.c
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: mlx42 libft $(NAME)

mlx42: $(MLX42_PATH)/build/libmlx42.a

$(MLX42_PATH)/build/libmlx42.a:
	@if [ ! -d "$(MLX42_PATH)" ]; then \
		git clone $(MLX42_REPO) $(MLX42_PATH); \
		cd $(MLX42_PATH) && git checkout $(MLX42_VERSION); \
	fi
	@mkdir -p $(MLX42_PATH)/build
	@cd $(MLX42_PATH) && cmake -B build && cmake --build build -j4

libft: $(LIBFT_PATH)/libft.a

$(LIBFT_PATH)/libft.a:
	@make all -C $(LIBFT_PATH)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJS)
	@rm -rf $(MLX42_PATH)/build

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@rm -rf $(MLX42_PATH)
	@rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re mlx42 libft