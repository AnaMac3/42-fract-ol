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

SRC_FILES= main.c events.c create_img.c hook_prueba.c mandelbrot.c

OBJ_DIR= ./obj
OBJ_FILES= $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

#BONUS_DIR= ./bonus

all: $(NAME)

$(FRT_LIB_NAME): $(OBJ_FILES) $(LIBFT_NAME)
	ar rcs $@ $(OBJ_FILES)

$(NAME): $(OBJ_FILES) $(FRT_LIB_NAME) $(LIBFT_NAME)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L. -lfractol -L$(LIBFT_DIR) -lft $(LINK_FLAGS) $(MLX_NAME) -o $(NAME)

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)
#la minilibx me genera dos .a
$(MLX_NAME):
	@make -C $(MLX_DIR) DEBUG=1 -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#bonus: all
#	@make -C $(BONUS_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)
#	@make clean -C $(BONUS_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re #bonus