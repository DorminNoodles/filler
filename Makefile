NAME = lchety.filler
CC = clang
SRC =	main.c							\
		init.c							\
		parsing.c						\
		play.c							\
		check_move.c					\

INC = -I includes -I libft/includes

FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix srcs/, $(SRC))
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(OBJ) $(INC) libft/libft.a -o resources/players/$(NAME)

%.o : srcs/%.c includes/filler.h
	$(CC) -c $< $(INC) -o $@

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
