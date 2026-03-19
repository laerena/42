NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I include

SRCS = src/main.c \
	   src/setup/args.c \
	   src/setup/files.c \
	   src/setup/pipe.c \
	   src/process/children.c \
	   src/process/redirects.c \
	   src/process/wait.c \
	   src/utils/error.c \
	   src/utils/free.c \
	   src/utils/string.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.c include/pipex.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re