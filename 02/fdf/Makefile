NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -Iincludes

SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft
GNL_DIR = gnl
MLX_DIR = mlx_linux

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

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -I/usr/include -I$(MLX_DIR)
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re