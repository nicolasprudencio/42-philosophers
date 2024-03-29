NAME	= philo
CC		= cc
RM		= rm -fr


SRCS 	= main.c init.c utils.c life.c
OBJS	= $(SRCS:%.c=%.o)
FLAGS	= -Werror -Wextra -Wall -g
LIB		= -pthread

ANSI	=	\033[0
YELLOW	=	;33
GREEN	=	;32
RED		=	;31

all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) $^ $(CFLAGS) $(LIB) -o $(NAME)
	@printf "\033[0;1;32m%s\033[0m\n" "Philos - Compiled successfully"

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

play:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 210 100 100 2

hell:
	valgrind --tool=helgrind ./$(NAME) 2 310 100 100 2

re: fclean all
