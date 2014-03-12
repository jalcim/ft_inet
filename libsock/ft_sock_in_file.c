/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock_in_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 04:45:51 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/12 19:29:26 by jalcim           ###   ########.fr       */
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
			error();
//		ft_strcpy(filename+2, filename);
//		filename[0] = '.';
//		filename[1] = '/';
		chdir(filename);
	}
	else if ((fd = open(filename, O_RDONLY, S_IRUSR)))
	{
		ft_putstr("filename sended = ");
		ft_putendl(filename);
		if (!fd)
			error();
		ft_sock_in_file(fd, socket);
	}
	else
		error();
	if (nb)
	{
		while ((Rfille = readdir(rep)) && Rfille->d_name[0] == '.')
			if (Rfille == NULL)
				error();
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
			error();
		ft_sock_in_file(socket, fd);
	}
	first = 0;
	if (nb--)
		first = ft_recv_file(socket, nb);

	chdir("..");
	return (1);
}

void ft_sock_in_file(int socket, int fd)
{
  char *buffer;
  int size;

  buffer = ft_fd_in_str(socket);
//  ft_putstr("sock_in_file = ");
//  ft_putstr(buffer);
//  write(1, "\n", 1);
  size = ft_strlen(buffer) + 1;
  write(fd, buffer, size);
  free(buffer);
}

char *ft_fd_in_str(int fd)
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
	printf("ft_fd_in_str buffer = :%s:\n", buffer);
  return (buffer);
}

char *ft_recv_filename(int sock)
{
    char *filename;
    int compt;
	char buf;

    filename = ft_strnew(256);
    compt = -1;
	while (read(sock, &buf, 1))
		  write(1, &buf, 1);
/*    while (read(sock, &filename[++compt], 1) && filename[compt] != '\0' && compt < 255)
*/       ;
    if (filename[compt] != '\0')
    {
        printf("invalide filename :%s:\n", filename);
        exit(0);
    }
    printf("filename = :%s:\n", filename);
    return (filename);
}
