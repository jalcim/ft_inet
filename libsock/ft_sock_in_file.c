/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock_in_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 04:45:51 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/03 05:55:26 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_inet.h"

void ft_send_file(int socket, char *filename)
{
	int fd;
	if ((fd = open(filename, O_RDONLY, S_IRUSR)) == -1)
		error();
	ft_sock_in_file(fd, socket);
}

void ft_recv_file(int socket, char *filename)
{
	int fd;
	if ((fd = open(filename, O_CREAT | O_WRONLY, S_IWUSR)) == - 1)
		error();
	ft_sock_in_file(socket, fd);
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
		if (!(buffer = realloc(buffer, sizestr + oct)))
			error();

		strncat(buffer, tmp, oct);
		buffer[sizestr + oct] = '\0';
		sizestr += oct;
	}
	free(tmp);
	printf("buffer = :%s:\n", buffer);
  return (buffer);
}
