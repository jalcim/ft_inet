/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clienttcp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:03:39 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/13 13:13:53 by scirciu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
typedef struct sockaddr_in t_sockaddr_in;
typedef struct in_addr t_in_addr;
typedef struct pollfd t_pollfd;
typedef struct sockaddr t_sockaddr;

#define PORT 1892
#define IP "10.11.13.12"

void error();
unsigned short ft_htons(unsigned short value);
unsigned int ft_htonl(unsigned int value);

int main()
{
	int sock;

	t_sockaddr_in sin = {0};

	char buffer[99999];


	printf("htonl = %u\nft_htonl = %u\n", htonl(65536), ft_htonl(65536));
	if ((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		error();

	sin.sin_addr.s_addr = inet_addr(IP);
	sin.sin_family = PF_INET;
	sin.sin_port = ft_htons(PORT);
	printf("connect\n");

	if (connect(sock, (t_sockaddr*)&sin, sizeof(t_sockaddr)) == -1)
		error();
	printf("connect\n");

	bzero(buffer, 20);
	strncpy(buffer, "yo manoooooooooooooyo manooooooooooooooyo manooooooooooooooo\0", 60);
	printf("buffer = :%s:\n", buffer);
	if (write(sock, buffer, 60) == -1)
		error();
	printf("send\n");

	sleep(2);
	close(sock);
	return (0);
}

void error()
{
	perror("error -> ");
	exit(errno);
}

unsigned short ft_htons(unsigned short value)
{
	return (value >> 8 | value << 8);
}

unsigned int ft_htonl(unsigned int value) // ca KIFFEEEE by scirciu
{
	char	*c;

	c = (char *)&value;
	return (c[3] | c[2] << 8 | c[1] << 16 | c[0] << 24);
}
