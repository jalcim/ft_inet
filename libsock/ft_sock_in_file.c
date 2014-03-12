/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock_in_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 04:45:51 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/12 01:07:25 by jalcim           ###   ########.fr       */
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
		if (!(rep = opendir(filename)))
			error();

	else if ((fd = open(filename, O_RDONLY, S_IRUSR)) == -1)
		error();
	ft_sock_in_file(fd, socket);

	if (nb && (Rfille = readdir(rep)))
	{
		if (--nb)
			ft_send_file(socket, Rfille->d_name, nb);
	}
}

void ft_recv_file(int socket, int nb)
{
	int fd;
	char download[500] = "./download/";
	char *filename;

	filename = ft_recv_filename(socket);
	ft_strcat(download, filename);
	if ((fd = open(download, O_CREAT | O_WRONLY, S_IWUSR)) == - 1)
		error();

	ft_sock_in_file(socket, fd);
	if (--nb)
		ft_recv_file(socket, nb);
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
		tmp[oct] = '\0';
		if (!(buffer = (char *)realloc(buffer, sizestr + oct)))
			error();

		strncat(buffer, tmp, oct);
		buffer[sizestr + oct] = '\0';
		sizestr += oct;
	}
	free(tmp);
	printf("buffer = :%s:\n", buffer);
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
