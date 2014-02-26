/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clienttcp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:03:39 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/26 20:48:23 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsock/ft_inet.h"
#include "../libft/libft.h"
#define PORT 4000
#define IP "10.11.12.1"

int ft_cli_socktcp(t_sockaddr_in *sin);
void ft_commutateur(int sock, char **argv);

int main(int argc, char **argv)
{
	int sock;
	t_sockaddr_in sin = {0};
	int err = 0;

	char mode;
	char filename[256] = {0};

	sock = ft_cli_socktcp(&sin);

	printf("port = %d\n", (int)sin.sin_port);
	errno = 0;
	if ((err = connect(sock, (t_sockaddr*)&sin, sizeof(t_sockaddr))))
	{
		if (errno == EACCES)
			printf("acces refuser");
		close(sock);
		error();
	}
	printf("connected\n");

	ft_commutateur(sock, argv);
	printf("send\n");

	sleep(2);
	close(sock);
	return (0);
}

void ft_commutateur(int sock, char **argv)
{
	char mode;
	char filename[256] = {0};

	mode = argv[1][0];//d f c
	write(sock, &mode, 1);

	if (mode == 'f')
	{
		strncpy(filename, argv[2], 255);
		strncat(filename, "\0", 1);
		ft_send_file(sock, filename);
	}
	else if (mode == 'c')
		ft_putstr_fd(argv[2], sock);
}

int ft_cli_socktcp(t_sockaddr_in *sin)
{
	int sock;

	if ((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		error();
	printf(inet_addr(IP) == ft_inet_addr(IP) ? "" : "inet_addr %d : ft %d\n", (int)inet_addr(IP), (int)ft_inet_addr(IP));
	sin->sin_addr.s_addr = ft_inet_addr(IP);
	sin->sin_family = PF_INET;
	printf(htons(PORT) == ft_htons(PORT) ? "" : "htonl = %u : ft = %u\n", htons(PORT), ft_htons(PORT));
	sin->sin_port = ft_htons(PORT);

	printf("connect\n");
	return (sock);
}

void error()
{
	perror("error -> ");
	exit(errno);
}
