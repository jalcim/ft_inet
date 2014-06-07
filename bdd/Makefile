NAME = bdd.a

SRC =	init_transit.c\
		transit.c\
		synch_data.c\
		fdbuild.c

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		gcc -g -Wall -Wextra -Werror -c $(SRC)
		ar rc $(NAME) $(SRCO)
		ranlib $(NAME)
clean:
		/bin/rm -f $(SRCO)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re