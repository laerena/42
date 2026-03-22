NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft
GNL_DIR = GNL
MLX_DIR = minilibx-linux

SRC = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/destroy.c \
	$(SRC_DIR)/hooks.c \
	$(SRC_DIR)/parse_size.c \
	$(SRC_DIR)/parse_fill.c \
	$(SRC_DIR)/pixel.c \
	$(SRC_DIR)/project.c \
	$(SRC_DIR)/line.c \
	$(SRC_DIR)/render.c\
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR)
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	cp -f $(MLX_DIR)/libmlx.dylib .
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f libmlx.dylib
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re