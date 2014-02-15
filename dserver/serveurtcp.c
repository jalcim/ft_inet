/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveurtcp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:32:17 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/15 08:59:28 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsock/ft_inet.h"
#define PORT 1290

int main()
{
	int sock;
	t_sockaddr_in serveur, client;
	char *buffer;
	t_pollfd event[1];
	int err;
	int size;
	int compt;

	if (!(buffer = (char *)malloc(1024 * sizeof(char))))
		error("error malloc -> ");
	bzero(buffer, sizeof(*buffer));
	ft_socktcp(&sock, PORT, &serveur);
	ft_waitsocktcp(sock, event, 0, -1);
	size = sizeof(t_sockaddr);
	if ((sock = accept(event[0].fd, (t_sockaddr *)&client, &size)) == -1)
		error();
	printf("connected\n");
	ft_recv_file(sock, "file");

	close(sock);
	close(event[0].fd);
	return (0);
}

void error(char *strerr)
{
  perror(strerr);
  exit(0);
}
