NAME = lchety.filler
CC = clang
SRC =	main.c							\
		init.c							\
		map.c							\
		parsing.c						\
		play.c							\
		check_move.c					\
		vector.c

INC =	libft/includes includes/

FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix srcs/, $(SRC))
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(OBJ) -I $(INC) libft/libft.a -o resources/players/$(NAME)

%.o : srcs/%.c filler.h
	$(CC) -c $< -I $(INC) -o $@

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
