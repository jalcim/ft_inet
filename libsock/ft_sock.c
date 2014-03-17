/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 08:50:10 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/17 22:03:13 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_inet.h"
#include "../libft/libft.h"

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
    if ((poll(event, sizeof(t_pollfd), time)) == -1)
        error("poll -> ");
	printf("listen\n");
    if (listen(event[0].fd, size_fille) == -1)//liste chaine ?
        error("listen -> ");
}

t_server *ft_serv_init()
{//initialise la structure server standar
	t_server *server;

	if (!(server = (t_server *)malloc(sizeof(t_server))))
		error("serv_init -> ");
	ft_bzero(server, sizeof(t_server));
	server->server = (t_sockaddr_in *)malloc(sizeof(t_sockaddr_in));
    ft_bzero(server->server, sizeof(t_sockaddr_in));
	server->list = NULL;
    server->connection = 0;
	return (server);
}

void waitsock(int fd)
{
	t_pollfd event;

	printf("wait\n");
    event.fd = fd;
    event.events = POLLIN;
	printf("poll\n");
    if ((poll(&event, sizeof(t_pollfd), 1)) == -1)
        error("poll -> ");
}
