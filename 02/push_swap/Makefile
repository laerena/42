NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

INCDIR = include
SRCDIR = src

SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/error.c \
       $(SRCDIR)/algo/is_sorted.c \
       $(SRCDIR)/algo/normalize.c \
       $(SRCDIR)/algo/small.c \
       $(SRCDIR)/algo/basic/chunk.c \
       $(SRCDIR)/algo/basic/radix.c \
       $(SRCDIR)/helper/ft_split.c \
       $(SRCDIR)/ops/ops_push.c \
       $(SRCDIR)/ops/ops_revrot.c \
       $(SRCDIR)/ops/ops_rotate.c \
       $(SRCDIR)/ops/ops_swap.c \
       $(SRCDIR)/parse/free_tokens.c \
       $(SRCDIR)/parse/parse.c \
       $(SRCDIR)/stack/stack_clear.c \
       $(SRCDIR)/stack/stack_init.c \
       $(SRCDIR)/stack/stack_pop.c \
       $(SRCDIR)/stack/stack_push.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCDIR)/push_swap.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

radix: re
	mv push_swap push_swap_radix

chunk:
	$(MAKE) re CFLAGS="$(CFLAGS) -DUSE_CHUNK"
	mv push_swap push_swap_chunk