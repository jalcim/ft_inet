/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_projection_memory.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 20:22:37 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/15 22:32:01 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include "../libft/libft.h"

void *projectm(int fd, int prot, int max_size);
int size_fd(int fd);

char *ft_readfd(int fd)
{
	char *str;

	str = (char *)projectm(fd, PROT_READ, size_fd(fd));
	ft_putstr(str);
	munmap(str, size_fd(fd));
}

int size_fd(int fd)
{
	struct stat status;

	fstat(fd, &status);

	return (status.st_size);
}

void *projectm(int fd, int prot, int max_size)
{
	void *addr = NULL;

	addr = mmap(addr, max_size, prot, MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED)
	{
		perror("echec");
		exit(0);
	}
	msync(addr, max_size, 0);
	return (addr);
}
