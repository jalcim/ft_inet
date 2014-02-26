/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveurtcp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:32:17 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/26 08:28:22 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsock/ft_inet.h"
#include "../libft/libft.h"
#include <signal.h>
#include <sys/types.h> 
#include <sys/wait.h>
#define PORT 3000
#define MAX_CLIENT 50

int main()
{
	t_server *server;

	server = (t_server *)malloc(sizeof(t_server));
	ft_bzero(server, sizeof(server));
	server->server = (t_sockaddr_in *)malloc(sizeof(t_sockaddr_in));
	ft_bzero(server->server, sizeof(t_sockaddr_in));
//	server = ft_serv_init();
	server->list = NULL;
	server->connection = 0;
	ft_socktcp(&server->sock, PORT, server->server);

	printf("sock = %d port = %d\n", server->sock, (int)server->server->sin_port);
	server->pid = 1;
//	while (server->pid)
//	{
		new_connect(server);
		printf("y\n");
		acceuil(server);
		printf("d\n");
		waitpid(server->pid, NULL, 0);
//	}
		printf("f\n");
	ft_serv_end(server);
	printf("end\n");
}

void acceuil(t_server *server)
{//devie suivant la commande 
	char cmd;
	char *filename;
	char *buffer;

	printf("acceuil\n");
	ft_accept(server);
	server->connection++;
	printf("connected\n");

//	if (!(server->pid = fork()))
//	{
		printf("fils\n");
		cmd = cmd_sock(server);
		printf("cmd = :%c:\n", cmd);
		if (cmd == 'd')
			printf("directory not gered\n");//file recursif
		else if (cmd == 'f')// f == file
		{
			filename = ft_recv_filename(server);
			ft_recv_file(server->sock, filename);
		}
		else if (cmd == 'c')// c == chat
		{
			printf("fd_in_str\n");
			buffer = ft_fd_in_str(server->sock);//, &buffer);
			printf("acceuil ~:~ buffer = :%s:\n", buffer);
			//envoie du buffer au shell via pipe
		}
		else if (cmd == 'x')
			printf("exec not gered\n");
		exit(0);
//	}
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
	if (server->sock == -1)
		printf("sock invalid\n");
//		ft_socktcp(&server->sock, PORT, &server->server);
	ft_waitsocktcp(server->sock, server->event, 1, 10);//sizeof(*server->event), -1);
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
