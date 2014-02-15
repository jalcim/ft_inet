#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/15 05:54:35 by jalcim            #+#    #+#              #
#    Updated: 2014/02/15 08:56:32 by jalcim           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRV = server
CLT = client

SSRC = dserver/serveurtcp.c
CSRC = dclient/clienttcp.c
LSOCK = libsock/ft_inetaddr.c libsock/ft_sock_in_file.c libsock/ft_sock.c
LFT = -L libft/ -lft

all : $(SRV) $(CLT)

$(SRV):
	gcc $(LFT) -o $(SRV) $(SSRC) $(LSOCK)
$(CLT):
	gcc $(LFT) -o $(CLT) $(CSRC) $(LSOCK)
clean:

fclean: clean
	rm $(SRV)
	rm $(CLT)
re: fclean all
