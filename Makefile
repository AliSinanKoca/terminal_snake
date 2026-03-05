NAME = snake_game
SRCS =	main.c			\
	srcs/fruit.c		\
	srcs/snake.c		\
	srcs/exit_protocol.c	\
	srcs/grid.c		\
	srcs/input_and_coll.c	\
	srcs/term_cntl.c
OBJS = $(SRCS:.c=.o)
INCLUDES = includes
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
