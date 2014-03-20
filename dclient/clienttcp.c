/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clienttcp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:03:39 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/19 21:09:30 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsock/ft_inet.h"
#include "../libft/libft.h"
#define PORT 34000
#define IP "127.0.0.1"
#define SIZE_FILENAME 256

int ft_cli_socktcp(t_sockaddr_in *sin);
void ft_commutateur(int sock, char **argv);

/*protocol :modif: eradication du protocol*/
//protocol :c/x: envoi du mode, envoi du buffer
//protocol :f: envoi du mode, envoi du nom de fichier, envoi du buffer
//protocol :d: envoi du mode, envoi du nombre de fichier, (re:)envoi du nom de fichier, envoi du buffer(goto re;)
//protocol :modif: envoi du nom d'utilisateur avant le mode

int main(int argc, char **argv)
{
	int sock;
	t_sockaddr_in sin = {0};

//char *user
	char mode;
	char filename[SIZE_FILENAME] = {0};

	if (argc != 3)
	{
		ft_putendl("error -> bad argument");
		exit(0);
	}
	sock = ft_cli_socktcp(&sin);

	printf("port = %d\n", (int)sin.sin_port);
	errno = 0;
	if ((connect(sock, (t_sockaddr*)&sin, sizeof(t_sockaddr))))
	{
		if (errno == EACCES)
			printf("acces refuser");
		close(sock);
		error("connect -> ");
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
		if (mode == 'f')
		{
//			write(sock, filename, ft_strlen(filename) + 1);
			ft_send_file(sock, filename, 0);
		}
		else
		{
			nb = ft_compt_dir(filename);
			nb_file = ft_itoa(nb);//a elliminer avec ft_send_dir
			ft_putendl_fd(nb_file, 1);
			write(sock, nb_file, ft_strlen(nb_file));
			write(sock, "\0", 1);
			ft_send_file(sock, filename, nb);
		}
	}
	else if (mode == 'c' || mode == 'x')
	{
		ft_putstr_fd(argv[2], sock);
		write(sock, "\0", 1);
	}
	else
		printf("no mode %c bad argument\n", mode);
}

int ft_cli_socktcp(t_sockaddr_in *sin)
{
	int sock;

	if ((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		error("socket -> ");
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
		if (Rfille->d_name[0] != '.')
			compt++;

	printf("compt_dir = %d\n", compt);
	return (compt);
}
