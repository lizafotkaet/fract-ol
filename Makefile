NAME = fract-ol
LIBFT_DIR = ./libft
MLX_DIR = ./MLX42
MLX_INC = $(MLX_DIR)/include
MLX_LIB = $(MLX_DIR)/build/libmlx42.a

LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
OBJ_DIR = obj
SRC = $(SRC_DIR)/main.c 
SRC += $(SRC_DIR)/image_stuff.c
SRC += $(SRC_DIR)/playground.c
SRC += $(SRC_DIR)/events.c
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
CC = gcc 
CFLAGS = -fsanitize=leak
INCLUDES = -I$(MLX_INC) -I$(LIBFT_DIR)
LIBS = -lmlx42 -ldl -lglfw -pthread -lm -L$(LIBFT_DIR) -L$(MLX_DIR)/build -lft 

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re