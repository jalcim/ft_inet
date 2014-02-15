/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clienttcp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:03:39 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/15 06:05:39 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsock/ft_inet.h"
#include "../libft/libft.h"
#define PORT 1290
#define IP "127.0.0.1"

int main()
{
	int sock;
	t_sockaddr_in sin = {0};
	char buffer[99999];
	int err;

	printf("htonl = %u\nft_htonl = %u\n", htonl(65536), ft_htonl(65536));
	if ((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		error();

	printf(inet_addr(IP) != ft_inet_addr(IP) ? "" : "origin %d : ft %d\n", (int)inet_addr(IP), (int)ft_inet_addr(IP));
	sin.sin_addr.s_addr = ft_inet_addr(IP);
	sin.sin_family = PF_INET;
	sin.sin_port = ft_htons(PORT);	
	printf("connect\n");

	if (connect(sock, (t_sockaddr*)&sin, sizeof(t_sockaddr)) == -1)
		error();
	printf("connected\n");

	bzero(buffer, 20);
	strncpy(buffer, "yo manoooooooooooooyo manooooooooooooooyo manooooooooooooooo\0", 60);
	printf("buffer = :%s:\n", buffer);
	ft_putstr_fd(buffer, sock);
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
