/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock_in_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 04:45:51 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/12 14:14:43 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_inet.h"

void ft_send_file(int socket, char *filename, int nb)
{
	static DIR *rep = NULL;
	t_dirent *Rfille = NULL;
	int fd;

	if (rep == NULL && nb)
	{
		ft_putstr_fd(filename, socket);
		if (!(rep = opendir(filename)))
			error();
	}
	else if ((fd = open(filename, O_RDONLY, S_IRUSR)))
	{
		if (!fd)
			error();
		ft_sock_in_file(fd, socket);
	}
	else
		error();
	if (nb && (Rfille = readdir(rep)))
	{
		if (nb--)
			ft_send_file(socket, Rfille->d_name, nb);
	}
}

int ft_recv_file(int socket, int nb)
{
//	static char download[500] = "./download/";
	static int first = 1;
	int fd;
	char *filename;
	int save;

	filename = ft_recv_filename(socket);
	if (first && nb)
	{
		ft_putstr("dir = ");
		ft_putendl(filename);
//		ft_strcat(download, filename);
		mkdir(filename, 0777);
//		ft_strcat(download, "/");
//		save = ft_strlen(download) + 1;
	}
//	ft_strcat(download + save, filename);
	if ((!first || !nb) && (fd = open(filename, O_CREAT | O_WRONLY, S_IWUSR)))
	{
		ft_putendl(filename);
		if (!fd)
			error();
		ft_sock_in_file(socket, fd);
	}
	first = 0;
	if (nb--)
		first = ft_recv_file(socket, nb);

	return (1);
}

void ft_sock_in_file(int socket, int fd)
{
  char *buffer;
  int size;

  buffer = ft_fd_in_str(socket);//, &buffer);
  size = ft_strlen(buffer);
  write(fd, buffer, size);
  free(buffer);
}

char *ft_fd_in_str(int fd)//, char **buffer)
{
	char *tmp;
	int sizestr;
	int oct;
	char *buffer;

	sizestr = 1;
	tmp = ft_strnew(1024);
	buffer = ft_strnew(sizestr);
	while ((oct = read(fd, tmp, 60)) > 0)
	{
		ft_putstr(tmp);
		tmp[oct] = '\0';
		if (!(buffer = (char *)realloc(buffer, sizestr + oct)))
			error();

		strncat(buffer, tmp, oct);
		buffer[sizestr + oct] = '\0';
		sizestr += oct;
	}
	free(tmp);
	printf("ft_fd_in_str buffer = :%s:\n", buffer);
  return (buffer);
}

char *ft_recv_filename(int sock)
{
    char *filename;
    int compt;

    filename = ft_strnew(256);
    compt = -1;
    while (read(sock, &filename[++compt], 1) && filename[compt] != '\0' && compt < 255)
        ;
    if (filename[compt] != '\0')
    {
        printf("invalide filename :%s:\n", filename);
        exit(0);
    }
    printf("filename = :%s:\n", filename);
    return (filename);
}
