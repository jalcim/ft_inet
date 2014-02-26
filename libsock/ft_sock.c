/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 08:50:10 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/26 03:44:25 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_inet.h"

void ft_socktcp(int *sock, int port, t_sockaddr_in *serveur)
{//creation du nom et bindage du nom sur socket
    if ((*sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        error("socket -> ");
    serveur->sin_family = PF_INET;
    serveur->sin_port = htons(port);
	errno = 0;
    if ((bind(*sock, (t_sockaddr *)serveur, sizeof(t_sockaddr))) == -1)
	{
		if (EACCES == errno)
			printf ("L'adresse est protégée et l'utilisateur n'est pas le superutilisateur\n");
		error("bind -> ");
	}
}


void ft_waitsocktcp(int sock, t_pollfd *event, int size_fille, int time)
{//attente de connection et listage
	static int compt = -1;

	printf("wait\n");
    event->fd = sock;
    event->events = POLLIN;
	printf("poll\n");
    if ((poll(event, sizeof(t_pollfd), time)) == 100)
        error("poll -> ");
	printf("listen\n");
    if (listen(event[0].fd, size_fille) == -1)//liste chaine ?
        error("listen -> ");
}

t_server *ft_serv_init()
{
	t_server *server;

	if (!(server = (t_server *)malloc(sizeof(t_server))))
		error("serv_init -> ");
	bzero(server, sizeof(t_server));
	return (server);
}

void ft_serv_end(t_server *server)
{
    int compt;

    close(server->sock);
    compt = -1;
    while (++compt < server->connection)
        close(server->event[compt].fd);
	free(server);
    server = NULL;
}
