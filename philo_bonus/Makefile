SRC_B = actions.c \
	cleanup.c \
	ft_atoi.c \
	init_data.c \
	init_time.c \
	philo_bonus.c \
	process.c \
	simulation.c \
	one_philo.c \
	monitor.c \
	parcing.c

OBJ_B = $(SRC_B:.c=.o)

header_b = header_bonus.h

NAME = philo_bonus

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_B) $(header_b)
	cc $(FLAGS) -c $(SRC_B)
	cc $(FLAGS) $(OBJ_B)  -o $(NAME)

clean:
	rm -f $(OBJ_B)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

