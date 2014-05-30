#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 13:59:15 by nbahri            #+#    #+#              #
#    Updated: 2014/03/26 05:43:18 by jalcim           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = chat.a

SRC =	init_chat.c\
	chat.c\
	servpipe.c\
	fdbuild.c\
	error.c

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c $(SRC)
		ar rc $(NAME) $(SRCO)
		ranlib $(NAME)
clean:
		/bin/rm -f $(SRCO)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
