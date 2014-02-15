/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock_in_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 04:45:51 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/15 09:07:06 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_inet.h"

void ft_send_file(int socket, char *filename)
{
	int fd;
	if ((fd = open(filename, O_RDONLY, S_IRUSR)) == -1)
		error();
	ft_file_in_sock(fd, socket);
}

void ft_recv_file(int socket, char *filename)
{
	int fd;
	if ((fd = open(filename, O_CREAT | O_WRONLY, S_IWUSR)) == - 1)
		error();
	ft_sock_in_file(socket, fd);
}

void ft_file_in_sock(int fd, int socket)
{
	char *buffer;
	int size;
	if (!(buffer = (char *)malloc(1024 * sizeof(char))))
		error();
	bzero(buffer, 1024);
	size = ft_fd_in_str(fd, buffer);
	write(socket, buffer, size);
	free(buffer);
}

void ft_sock_in_file(int socket, int fd)
{
  char *buffer;
  int size;

  if (!(buffer = (char *)malloc(1024 * sizeof(char))))
	  error();
  bzero(buffer, 1024);
  size = ft_fd_in_str(socket, buffer);
  write(fd, buffer, size);
  free(buffer);
}

int ft_fd_in_str(int fd, char *buffer)
{
	char *tmp;
	int sizestr;
	int size;
	int ret;
	char c;

	size = 1024;
	tmp = ft_strnew(size);
	if (fd == -1 || buffer == NULL)
		error();

	while ((read(fd, tmp, 60)) > 0)
	{
		ret = ft_strlcar(tmp, '\0');
		if ((ret - size) > 0)
		{
			ft_realloc(buffer, sizeof(*buffer) + 1024);
			sizestr = ft_strlen(buffer);
			size += 1024
		}
	}
	buffer[sizestr] = '\0';
	free(tmp);

  return (sizestr);
}
