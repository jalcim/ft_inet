/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveurtcp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:32:17 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/25 22:50:21 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsock/ft_inet.h"
#include "../libft/libft.h"
#include <signal.h>
#include <sys/types.h> 
#include <sys/wait.h>
#define PORT 24000
#define MAX_CLIENT 50
#define SIZE_FILENAME 256

//protocol :c/x: envoi du mode, envoi du buffer
//protocol :f: envoi du mode, envoi du nom de fichier, envoi du buffer
//protocol :d: envoi du mode, envoi du nombre de fichier, (re:)envoi du nom de fichier, envoi du buffer(goto re;)
//protocol :modif: envoi du nom d'utilisateur avant le mode
//protocol :modif: envoi de la taille de chaque string apres le mode sur 1 unsigned int (si la taille est au max de l'uint la fonction d'envoi/reception devien recursif)
t_server *recup(t_server *server);

int main()
{
	shell_server();

	return (0);
}

void servershell(int pid)
{
	t_server *server;

	signal(SIGINT, ft_serv_end);

	write(1, "server\n", 7);
	server = ft_serv_init();
	recup(server);
	ft_socktcp(&server->sock, PORT, server->server);
	new_connect(server);

//	server->pid = 1;
//	while (server->pid)
		acceuil(server, pid);
//	waitpid(server->pid, NULL, 0);
}

void acceuil(t_server *server, int pid)
{
	char cmd;
	char *user;//[user]
	char *buffer;
	int nb_dir;

	printf("acceuil\n");
	ft_accept(server);
	server->connection++;
	printf("connected\n");

	user = ft_fd_in_str(server->sock);//[user]
	ft_putendl(user);//[user]
/*	if (!(server->pid = fork()))
	{*/
		printf("fils\n");
//		if (!(user = getenv("USER=")))//pour les infos client (dans le client(ca na rien a foutre la !!!))
//			error();
		cmd = cmd_sock(server->sock);
		printf("cmd = :%c:\n", cmd);
		if (cmd == 'd' || cmd == 'f')
		{
			nb_dir = 0;
			if (cmd == 'd')
				nb_dir = nb_dir_sock(server->sock);
			ft_recv_file(server->sock, nb_dir);
		}
		else if (cmd == 'c' || cmd == 'x')
		{
			buffer = ft_fd_in_str(server->sock);//reception de la string sur la socket
			printf("serv buffer = :%s:\n", buffer);
			servcom(cmd, user, buffer, pid);//envoie du buffer au shell via pipe [user]
		}
		else
			printf("no mode %c bad argument\n", cmd);
		ft_putstr("server : mort du processus fils\n");

		close(server->sock);
		exit(0);
/*	}*/
}

char cmd_sock(int sock)
{
	char cmd;

	read(sock, &cmd, 1);
	return (cmd);
}

void new_connect(t_server *server)
{
	wait_connect(server);
	server->connection++;
	printf("connected\n");
}

void wait_connect(t_server *server)//int *sock, t_pollfd *event, int size_file)
{//creation socket attente et acceptation de connection
	server->client = (t_client *)malloc(sizeof(t_client));
	bzero(server->client, sizeof(t_client));
	if (!server->client->event)
		server->client->event = (t_pollfd *)malloc(sizeof(t_pollfd));
	if (server->sock == -1)
		printf("sock invalid\n");
//		ft_socktcp(&server->sock, PORT, &server->server);
	ft_waitsocktcp(server->sock, server->client->event, 1, 1);//sizeof(*server->event), -1);
	printf("ok\n");
}

void ft_accept(t_server *server)
{
	socklen_t size;

	size = sizeof(t_sockaddr);
	server->client->info = (t_sockaddr_in *)malloc(size);
	bzero(server->client->info, size);

	server->client->next = server->list;
	server->list = server->client;

	if ((server->sock = accept(server->client->event->fd, (t_sockaddr *)server->client->info, &size)) == -1)
		error("accept -> ");
}

void ft_serv_end()
{//detruit la structure server standar
    t_server *server;
	int pid;

    server = recup(NULL);
    close(server->sock);
    free(server->client);
    free(server);
	pid = ft_pidsave(0);
	kill(pid, SIGINT);
    exit(0);
}

t_server *recup(t_server *server)
{
	static t_server *save = NULL;

	if (server)
		save = server;
	else
		return (save);
	return (NULL);
}
