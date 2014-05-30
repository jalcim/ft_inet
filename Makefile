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
#SLSOCK = libsock/ft_inetaddr.c libsock/ft_sock_in_file.c libsock/ft_sock.c libsock/servcom.c libsock/ft_readfd.c
#CLSOCK = libsock/ft_inetaddr.c libsock/ft_sock_in_file.c libsock/ft_sock.c libsock/ft_readfd.c
LFT = -L libft/ -lft
FLAG = -Wall -Werror -Wextra

all : $(SRV) $(CLT)

$(SRV):
	#gcc $(FLAG) $(LFT) $(SSRC) $(SLSOCK) chat/chat.a -o $(SRV)
	gcc $(FLAG) $(LFT) $(SSRC) main.c libsock/ft_inet.a chat/chat.a -o $(SRV)
$(CLT):
	#gcc $(FLAG) $(LFT) $(CSRC) $(CLSOCK) -o $(CLT)
	gcc $(FLAG) $(LFT) $(CSRC) libsock/ft_inet.a -o $(CLT)
clean:

fclean: clean
	rm $(SRV)
	rm $(CLT)

re: fclean all
