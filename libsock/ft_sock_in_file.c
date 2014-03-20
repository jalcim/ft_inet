/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock_in_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 04:45:51 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/20 07:19:07 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_inet.h"

void ft_send_file(int socket, char *filename, int nb)
{
	static DIR *rep = NULL;
	t_dirent *Rfille = NULL;
	int fd;
	char ok;

	printf("%d nb\n", nb);
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
//
		ft_putstr("filename sended = ");
		ft_putendl(filename);
//
		if (!fd)
			error("open ->");
		ft_sendfile(fd, socket);//ft_sock_in_file(fd, socket);
//		write(socket, "\0", 1);
		read(socket, &ok, 1);//attente de confirmation
	}
	else
		error("bad request -> ");
	if (nb)
	{
		while ((Rfille = readdir(rep)) && Rfille->d_name[0] == '.')
			if (Rfille == NULL)
				error("readdir -> ");
//
		ft_putstr("filename repere = ");
		ft_putendl(Rfille->d_name);
		printf("nb = %d\n", nb);
//
		if (nb--)
		{
			ft_putendl("vrai");
			ft_send_file(socket, Rfille->d_name, nb);
		}
		else
			ft_putendl("faux");
	}
}

int ft_recv_file(int socket, int nb)
{
	static int first = 1;
	int fd;
	char *filename;
	int save;

	static int compt = -1;

	printf("%d nb ; %d fichier\n", nb, ++compt);

	sleep(1);
	filename = ft_recv_filename(socket);
	printf("first == %d\n", first);
	if (first && nb)
	{
		ft_putstr("dir = ");
		ft_putendl(filename);
		mkdir(filename, 0777);
		chdir(filename);
	}
	else if ((!first || !nb) && (fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)))
	{
		ft_putstr("filename f = ");
		ft_putendl(filename);
		if (!fd)
			error("open -> ");

		ft_putendl("reception\n");
		ft_recvfile(socket, fd);//ft_sock_in_file(socket, fd);
		ft_putendl("ok ?\n");
		//donc confirmation
		write(socket, "1", 1);
	}
	first = 0;
	if (nb--)
	{
		ft_putendl("vrai");
		first = ft_recv_file(socket, nb);
	}
	else
		ft_putendl("faux");

	chdir("..");
	return (1);
}

void ft_fusion(char *buffer, char *tmp);
char *ft_fd_in_str(int fd)
{
    char *tmp;
    char *buffer;
    int compt;

    compt = -1;
    tmp = ft_strnew(1024);
    buffer = ft_strnew(1);
    buffer[0] = '\0';
    while (read(fd, &tmp[++compt], 1) > 0 && tmp[compt] != '\0')
    {
        if (compt == 1022)
        {
            ft_putendl(tmp);
            tmp[compt + 1] = '\0';
            ft_fusion(buffer, tmp);
            compt = -1;
        }
    }
    tmp[compt] = '\0';
    ft_fusion(buffer, tmp);
    free(tmp);

    printf("ft_fd_in_str buffer = :%s:\n", buffer);
    return (buffer);
}

void ft_fusion(char *buffer, char *tmp)
{
    if (!(buffer = (char *)realloc(buffer, (ft_strlen(buffer) + ft_strlen(tmp)) + 1)))
        error("realloc ->");
    ft_strcat(buffer, tmp);
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
