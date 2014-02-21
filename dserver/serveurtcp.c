/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveurtcp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:32:17 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/21 17:55:25 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsock/ft_inet.h"
#include "../libft/libft.h"
#define PORT 1000
#define MAX_CLIENT 50

int main()
{
	t_server *server;
	int pid;

	server = ft_serv_init();
	server->list = NULL;
	server->connection = 0;
	ft_socktcp(&server->sock, PORT, &server->server);
	pid = 1;
	while (pid)
	{
		printf("pere\n");
		new_connect(server);
		acceuil(server);
	}
	ft_serv_end(server);
}

void acceuil(t_server *server)
{//devie suivant la commande 
	char cmd;
	char *filename;
	char *buffer;

	printf("acceuil\n");
	ft_accept(server);
	
	if (!(server->pid = fork()))
	{
		printf("fils\n");
		cmd = cmd_sock(server);
		if (cmd == 'd')
			;//file recursif
		else if (cmd == 'f')// f == file
		{
			filename = ft_recv_filename(server);
			ft_recv_file(server->sock, filename);
		}
		else if (cmd == 'c')// c == chat
		{
			ft_fd_in_str(server->sock, buffer);
			//envoie du buffer au shell via pipe
		}
		exit(0);
	}
}

char cmd_sock(t_server *server)
{
	char cmd;

	read(server->sock, &cmd, 1);
	return (cmd);
}

char *ft_recv_filename(t_server *server)
{
	char *filename;

	filename = ft_strnew(256);
	read(server->sock, filename, 255);
	filename[255] = '\0';
	return (filename);
}

void new_connect(t_server *server)
{
	wait_connect(server);
	server->connection++;
	printf("connected\n");
}

void wait_connect(t_server *server)//int *sock, t_pollfd *event, int size_file)
{//creation socket attente et acceptation de connection
	if (!server->event)
		server->event = (t_pollfd *)malloc(MAX_CLIENT * (int)sizeof(t_pollfd));
//	if (server->sock == -1)
//		ft_socktcp(&server->sock, PORT, &server->server);
	ft_waitsocktcp(server->sock, server->event, sizeof(*server->event), -1);
	printf("ok\n");
}

void ft_accept(t_server *server)
{
	int size;

	size = sizeof(t_sockaddr);
	server->client = (t_client *)malloc(sizeof(t_client));
	bzero(server->client, sizeof(t_client));
	server->client->info = (t_sockaddr_in *)malloc(size);
	bzero(server->client->info, size);

	server->client->next = server->list;
	server->list = server->client;

	if ((server->sock = accept(server->event->fd, (t_sockaddr *)server->client->info, &size)) == -1)
		error("accept -> ");
}

void error(char *strerr)
{
  perror(strerr);
  exit(0);
}
