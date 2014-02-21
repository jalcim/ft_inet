/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock_in_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 04:45:51 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/21 15:55:03 by jalcim           ###   ########.fr       */
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

  size = ft_fd_in_str(socket, buffer);
  write(fd, buffer, size);
  free(buffer);
}

int ft_fd_in_str(int fd, char *buffer)
{
	char *tmp;
	int sizestr;
	int size;
	int itmp;
	char compt;

	if (fd == -1 || buffer == NULL)
		error();

	sizestr = 0;
	size = 1024;
	tmp = ft_strnew(1024);
	buffer = ft_strnew(1024);

	while ((read(fd, tmp, 60)) > 0)
	{
		if ((sizestr + ft_strlen(tmp)) >= (size - sizestr))
		{
			ft_strcat(buffer, tmp);
			if (!(ft_realloc(buffer, sizeof(*buffer) + itmp)))
				error();
			size += 1024;
		}
		strncat(buffer, tmp, ft_strlen(tmp));
		sizestr = ft_strlen(buffer);
	}
	buffer[sizestr] = '\0';
	free(tmp);

  return (sizestr);
}
