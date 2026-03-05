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
       $(SRCDIR)/algo/turk/turk_find.c \
       $(SRCDIR)/algo/turk/turk_cost.c \
       $(SRCDIR)/algo/turk/turk_sort.c \
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

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

turk:
	$(MAKE) re NAME=push_swap_turk

chunk:
	$(MAKE) re NAME=push_swap_chunk CFLAGS="$(CFLAGS) -DUSE_CHUNK"

radix:
	$(MAKE) re NAME=push_swap_radix CFLAGS="$(CFLAGS) -DUSE_RADIX"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f push_swap push_swap_turk push_swap_chunk push_swap_radix

re: fclean all

.PHONY: all clean fclean re turk chunk radix