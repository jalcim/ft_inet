#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/15 05:54:35 by jalcim            #+#    #+#              #
#    Updated: 2014/03/25 05:55:40 by jalcim           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRV = server
CLT = client

SSRC = dserver/serveurtcp.c
CSRC = dclient/clienttcp.c

LIB =	libft/libft.a \
	libsock/ft_inet.a \
	chat/chat.a

FLAG = -Wall -Werror -Wextra

all : $(SRV) $(CLT)

$(SRV):
	#gcc $(FLAG) $(LFT) $(SSRC) $(SLSOCK) chat/chat.a -o $(SRV)
	gcc $(FLAG) $(LIB) $(SSRC) main.c -o $(SRV)
$(CLT):
	#gcc $(FLAG) $(LFT) $(CSRC) $(CLSOCK) -o $(CLT)
	gcc $(FLAG) $(LIB) $(CSRC) libsock/ft_inet.a -o $(CLT)
clean:

fclean: clean
	rm $(SRV)
	rm $(CLT)

re: fclean all
