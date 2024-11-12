NAME= fractol

CC= cc
CFLAGS= -Wall -Wextra -Werror -g

LIBFT_DIR= ./my_libft
LIBFT_NAME= $(LIBFT_DIR)/libft.a

FRT_LIB= libfractol.h
FRT_LIB_NAME= libfractol.a

MLX_DIR= ./MLX42
MLX_NAME= $(MLX_DIR)/build/libmlx42.a

HEADERS= -I ./include -I $(MLX_DIR)/include/MLX42

LINK_FLAGS= -ldl -lglfw -pthread -lm

SRC_FILES= main.c events.c events_2.c draw.c color.c \
			mandelbrot.c julia.c burning_ship.c 

OBJ_DIR= ./obj
OBJ_FILES= $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

all: $(NAME)

$(FRT_LIB_NAME): $(OBJ_FILES) $(LIBFT_NAME)
	ar rcs $@ $(OBJ_FILES)

$(NAME): $(OBJ_FILES) $(FRT_LIB_NAME) $(LIBFT_NAME) $(MLX_NAME)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L. -lfractol -L$(LIBFT_DIR) -lft $(LINK_FLAGS) $(MLX_NAME) -o $(NAME)

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(MLX_NAME):
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build -j4
#	@make -C $(MLX_DIR) DEBUG=1 -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
	@rm -rf $(MLX_DIR)/build
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(FRT_LIB_NAME)
	@make fclean -C $(LIBFT_DIR) 

re: fclean all

.PHONY: all clean fclean re