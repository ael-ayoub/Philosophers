SRC = ft_atoi.c \
	init_data.c \
	philosofer.c \
	init_time.c \
	simulation.c \
	threads.c \
	even_odd.c \
	actions.c \
	cleanup.c \
	one_philo.c \
	monitor.c

header = header.h

OBJ = $(SRC:.c=.o)

NAME = philo

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC) $(header)
	cc $(FLAGS) -c $(SRC)
	cc $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
