/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock_in_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 04:45:51 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/17 22:42:36 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_inet.h"

void ft_send_file(int socket, char *filename, int nb)
{
	static DIR *rep = NULL;
	t_dirent *Rfille = NULL;
	int fd;

	ft_putstr_fd(filename, socket);
	write(socket, "\0", 1);
	if (rep == NULL && nb)
	{
		if (!(rep = opendir(filename)))
			error("opendir -> ");
		chdir(filename);
	}
	else if ((fd = open(filename, O_RDONLY, S_IRUSR)))
	{
		ft_putstr("filename sended = ");
		ft_putendl(filename);
		if (!fd)
			error("open ->");
		ft_sendfile(fd, socket);//ft_sock_in_file(fd, socket);
		write(socket, "\0", 1);
	}
	else
		error("bad request -> ");
	if (nb)
	{
		while ((Rfille = readdir(rep)) && Rfille->d_name[0] == '.')
			if (Rfille == NULL)
				error("readdir -> ");
		ft_putstr("filename repere = ");
		ft_putendl(Rfille->d_name);
		if (nb--)
			ft_send_file(socket, Rfille->d_name, nb);
	}
}

int ft_recv_file(int socket, int nb)
{
	static int first = 1;
	int fd;
	char *filename;
	int save;

	static int compt = -1;

	printf("%d fichier\n", ++compt);

	filename = ft_recv_filename(socket);
	if (first && nb)
	{
		ft_putstr("dir = ");
		ft_putendl(filename);
		mkdir(filename, 0777);
		chdir(filename);
	}
	else if ((!first || !nb) && (fd = open(filename, O_CREAT | O_WRONLY, S_IWUSR)))
	{
		ft_putstr("filename f = ");
		ft_putendl(filename);
		if (!fd)
			error("open -> ");
		ft_putendl("reception\n");
		ft_recvfile(socket, fd);//ft_sock_in_file(socket, fd);
		ft_putendl("aaaaaaaaaaz\n");
	}
	first = 0;
	if (nb--)
		first = ft_recv_file(socket, nb);

	chdir("..");
	return (1);
}

char *ft_recv_filename(int sock)
{
    char *filename;
    int compt;
	char buf;

    filename = ft_strnew(256);
    compt = -1;
    while (read(sock, &filename[++compt], 1) && filename[compt] != '\0' && compt < 255)
		;
    if (filename[compt] != '\0')
    {
        printf("invalide filename :%s:\n", filename);
        exit(0);
    }
	else
		printf("filename = :%s:\n", filename);

    return (filename);
}
