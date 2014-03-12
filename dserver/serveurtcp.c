/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveurtcp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:32:17 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/12 19:20:23 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsock/ft_inet.h"
#include "../libft/libft.h"
#include <signal.h>
#include <sys/types.h> 
#include <sys/wait.h>
#define PORT 34000
#define MAX_CLIENT 50
#define SIZE_FILENAME 256

//protocol :c/x: envoi du mode, envoi du buffer
//protocol :f: envoi du mode, envoi du nom de fichier, envoi du buffer
//protocol :d: envoi du mode, envoi du nombre de fichier, (re:)envoi du nom de fichier, envoi du buffer(goto re;)
//protocol :modif: envoi du nom d'utilisateur avant le mode
//protocol :modif: envoi de la taille de chaque string apres le mode sur 1 unsigned int (si la taille est au max de l'uint la fonction d'envoi/reception devien recursif)
int nb_dir_sock(int sock);
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

	server->pid = 1;
//	while (server->pid)
//	{
		acceuil(server, pid);
		waitpid(server->pid, NULL, 0);
//	}
}

void acceuil(t_server *server, int pid)
{//devie suivant la commande 
	char cmd;
//	char *user
	char *filename;
	char *buffer;
	int size;
	int nb_dir;

	printf("acceuil\n");
	ft_accept(server);
	server->connection++;
	printf("connected\n");

//	new_struct_client(server);
/*	if (!(server->pid = fork()))
	{*/
		printf("fils\n");
//		if (!(user = getenv("USER=")))//pour les infos client
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
		else if (cmd == 'c' || cmd == 'x')// c == chat ou commande a distance
		{
			buffer = ft_fd_in_str(server->sock);//reception de la string sur la socket
			printf("serv buffer = :%s:\n", buffer);
			servcom(cmd, buffer, pid);//envoie du buffer au shell via pipe
		}
		else
			printf("no mode %c bad argument\n", cmd);
		ft_putstr("server : mort du processus fils\n");
		close(server->sock);
		exit(0);
/*	}*/
}

int nb_dir_sock(int sock)
{
	char nb_dir[255];
	int compt;

	compt = -1;
	while (compt <= 255 && read(sock, &nb_dir[++compt], 1) && nb_dir[compt] != '\0')
		;
	ft_putstr("nb_dir = ");
	ft_putendl(nb_dir);
	if (nb_dir[compt] != '\0')
		return (0);
	return (atoi(nb_dir));
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
	int size;

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
    int compt;
    t_server *server;

    server = recup(NULL);
    close(server->sock);
    compt = -1;
    while (++compt < 2)//server->connection)
		close(server->client->event[compt].fd);
    free(server->client);
    free(server);
    server = NULL;
    exit(0);
}

t_server *recup(t_server *server)
{
	static t_server *save;

	if (server)
		save = server;
	else
		return (save);
}

void error(char *strerr)
{
  perror(strerr);
  exit(0);
}
