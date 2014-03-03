/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveurtcp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:32:17 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/03 05:56:11 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsock/ft_inet.h"
#include "../libft/libft.h"
#include <signal.h>
#include <sys/types.h> 
#include <sys/wait.h>
#define PORT 4000
#define MAX_CLIENT 50
#define SIZE_FILENAME 256

int main()
{
	shell_server();
//	pause();
	sleep(10);
	return (0);
}

void servershell(int pid)
{
	t_server *server;

	write(1, "server\n", 7);
	server = ft_serv_init();
	ft_socktcp(&server->sock, PORT, server->server);

//	server->pid = 1;
//	while (server->pid)
//	{
		new_connect(server);
		acceuil(server, pid);
		waitpid(server->pid, NULL, 0);
//	}

	ft_serv_end(server);
	printf("end\n");
}
//protocol :structure de control contenand les infos de livraison(int size, nb buffer, (char **)nom fichier -> (char ***)buffer) char buffer[][]
//protocol :c/x: envoi du mode, envoi du buffer
//protocol :f: envoi du mode, envoi du nom de fichier, envoi du buffer
//protocol :d: envoi du mode, envoi du nombre de fichier, (re:)envoi du nom de fichier, envoi du buffer(goto re;)
//protocol :modif: envoi du nom d'utilisateur avant le mode
//protocol :modif: envoi de la taille de chaque string apres le mode sur 1 unsigned int (si la taille est au max de l'uint la fonction d'envoi/reception devien recursif)
void acceuil(t_server *server, int pid)
{//devie suivant la commande 
	char cmd;
//	char *user
	char *filename;
	char *buffer;
	int size;

	printf("acceuil\n");
	ft_accept(server);
	server->connection++;
	printf("connected\n");

	if (!(server->pid = fork()))
	{
		printf("fils\n");
//		if (!(user = getenv("USER=")))//pour les infos client
//			error();
		cmd = cmd_sock(server->sock);
		printf("cmd = :%c:\n", cmd);
		if (cmd == 'd')
			printf("directory not gered\n");//file recursif
		else if (cmd == 'f')// f == file
		{
			
			filename = ft_recv_filename(server->sock);
			ft_recv_file(server->sock, filename);
			//archiveur(cmd, filename, buffer);
		}
		else if (cmd == 'c' || cmd == 'x')// c == chat ou commande a distance
		{
//			size = ft_recept_size(server->sock);//reception de la taille de la prochaine chaine
			buffer = ft_fd_in_str(server->sock);//reception de la string sur la socket
			printf("serv buffer = :%s:\n", buffer);
			servcom(cmd, buffer, pid);//envoie du buffer au shell via pipe
		}
/*		else if (cmd == 'x')
		{
			buffer = ft_fd_in_str(server->sock);//, &buffer);
			printf("serv buffer = :%s:\n", buffer);
			servcom(cmd, buffer, pid);//envoie du buffer au shell via pipe
		}
*/		else
			printf("no mode %c bad argument\n", cmd);
		printf("mort du fils\n");
		exit(0);
	}
}

char cmd_sock(int sock)
{
	char cmd;

	read(sock, &cmd, 1);
	return (cmd);
}

int ft_recept_size(int sock)
{
	char size[4];

	read(sock, size, 4);
	return (atoi(size));
}
char *ft_recv_filename(int sock)
{
	char *filename;
	int compt;

	filename = ft_strnew(SIZE_FILENAME);
	compt = -1;
	while (read(sock, &filename[++compt], 1) && filename[compt] != '\0' && compt < SIZE_FILENAME)
		;
	if (!(compt < SIZE_FILENAME))
	{
		printf("filename invalide\n");
		exit(0);
	}
	printf("filename = :%s:\n", filename);
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
	ft_waitsocktcp(server->sock, server->event, 1, 1);//sizeof(*server->event), -1);
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
