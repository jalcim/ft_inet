/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clienttcp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:03:39 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/12 01:08:06 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsock/ft_inet.h"
#include "../libft/libft.h"
#define PORT 24000
#define IP "127.0.0.1"
#define SIZE_FILENAME 256

int ft_cli_socktcp(t_sockaddr_in *sin);
void ft_commutateur(int sock, char **argv);

//protocol :c/x: envoi du mode, envoi du buffer
//protocol :f: envoi du mode, envoi du nom de fichier, envoi du buffer
//protocol :d: envoi du mode, envoi du nombre de fichier, (re:)envoi du nom de fichier, envoi du buffer(goto re;)
//protocol :modif: envoi du nom d'utilisateur avant le mode
//protocol :modif: envoi de la taille de chaque string apres le mode sur 1 unsigned int (si la taille est au max de l'uint la fonction d'envoi/reception devien recursif)

int main(int argc, char **argv)
{
	int sock;
	t_sockaddr_in sin = {0};
	int err = 0;

//char *user
	char mode;
	char filename[SIZE_FILENAME] = {0};

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
//user = getenv(USER=);
//ft_putstr_fd(user, sock);
	ft_commutateur(sock, argv);
	printf("send\n");

	sleep(2);
	close(sock);
	return (0);
}

void ft_commutateur(int sock, char **argv)
{
	char csize[4];
	int size;
	char mode;
	char filename[SIZE_FILENAME] = {0};
	char *nb_file;
	int nb;

	mode = argv[1][0];//d f c
	write(sock, &mode, 1);

	if (mode == 'f' || mode == 'd')
	{
		ft_strncpy(filename, argv[2], 255);
		write(sock, filename, ft_strlen(filename) + 1);
		if (mode == 'f')
			ft_send_file(sock, filename, 0);
		else
		{
			nb = ft_compt_dir(filename);
			nb_file = ft_itoa(nb);//a elliminer avec ft_send_dir
			write(sock, nb_file, ft_strlen(nb_file));
			ft_send_file(sock, filename, nb);
		}
	}
	else if (mode == 'c' || mode == 'x')
		ft_putstr_fd(argv[2], sock);
	else
		printf("no mode %c bad argument\n", mode);
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

int ft_compt_dir(char *namedir)//a elliminer en upgradant ft_send_dir
{
	DIR *rep;
	t_dirent *Rfille;
	int compt;

	compt = 0;
	rep = opendir(namedir);
	while (Rfille = readdir(rep))
		compt++;

	return (compt);
}
void error()
{
	perror("error -> ");
	exit(errno);
}
