NAME	= philo
CC		= cc -g
RM		= rm -fr

OBJS_DIR = objects/
OBJS_ALL = $(addprefix $(OBJS_DIR), $(SRCS:%.c=%.o))
UTILS	= ft_atoi.c ft_atol.c ft_isdigit.c ft_isnbr.c ft_putstr.c utils.c
UTILS	:= $(addprefix utils/, $(UTILS))
SRCS	= main.c init.c life.c monitoring.c
SRCS	+= $(UTILS)
OBJS	:= $(addprefix $(OBJS_DIR), $(SRCS:%.c=%.o))
CFLAGS	= -Werror -Wextra -Wall
LIB		= -pthread

all: $(OBJS_ALL) $(NAME)
	@printf "\033[0;1;32m%s\033[0m\n" "Philos - Compiled successfully"

$(OBJS_DIR)%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(C_FLAGS) -c $< -o $@

$(NAME): $(OBJS_ALL)
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(LIB) -o $@

clean:
	$(RM) objects

fclean: clean
	$(RM) $(NAME)

play:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4 210 100 100 2

hell:
	valgrind --tool=helgrind ./$(NAME) 5 800 200 200

re: fclean all
