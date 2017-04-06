NAME = lchety.filler
CC = clang
SRC =	main.c							\
		init.c							\
		map.c							\
		parsing.c						\
		play.c							\
		del.c							\
		score_map.c

INC =	libft/includes

FLAGS = -Wall -Wextra -Werror -g
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(OBJ) -I $(INC) libft/libft.a -o $(NAME)

%.o : %.c
	$(CC) -c $< -I $(INC) -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
