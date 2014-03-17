/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_projection_memory.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 20:22:37 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/16 16:23:12 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_inet.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>

char *ft_readfd(int fd, int nb_oct)
{
    char *str;

    str = (char *)projectm(fd, PROT_READ, nb_oct);

    return (str);
}

char *ft_writefd(int fd, int nb_oct)
{
    char *str;

    str = (char *)projectm(fd, PROT_WRITE, nb_oct);

    return (str);
}

int size_fd(int fd)
{
    struct stat status;

    fstat(fd, &status);

    return (status.st_size);
}

void *projectm(int fd, int prot, int nb_oct)
{
    void *addr = NULL;

    addr = mmap(addr, nb_oct, prot, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
		error();
    msync(addr, nb_oct, 0);
    return (addr);
}

void ft_sendfile(int fd, int sock)
{
    char *str;
    int nb_oct;

    nb_oct = size_fd(fd);
    str = ft_readfd(fd, nb_oct);
    write(sock, str, nb_oct);

    munmap(str, nb_oct);
}

void ft_recvfile(int sock, int fd)
{//vu que l'on ne peux apperement pas projeter une socket
    char *str;
    int nb_oct;
    char *formate;

    nb_oct = size_fd(sock);

/*  a defaut d'un appel system portable du style mremap */
    formate = (char *)malloc(nb_oct);
    ft_memset(formate, '\0', nb_oct);
    write(fd, formate, nb_oct);
    free(formate);

    str = ft_writefd(fd, nb_oct);
    read(sock, str, nb_oct);

    munmap(str, nb_oct);
}

int redirfd(int fd1, int fd2)
{

    char *str1;
    int nb_oct;
    char *str2;
    char *formate;

    nb_oct = size_fd(fd1);
    str1 = ft_readfd(fd1, size_fd(fd1));

    formate = (char *)malloc(nb_oct);
    memset(formate, '\0', nb_oct);
    write(fd2, formate, nb_oct);
    free(formate);

    str2 = ft_writefd(fd2, size_fd(fd2));
    memcpy(str2, str1, nb_oct);
    read(fd2, str1, size_fd(fd1));

    munmap(str1, nb_oct);
    munmap(str1, nb_oct);
}

char *ft_fd_in_str(int fd)
{
	int size;
	char *buffer;

	size = size_fd(fd);
	buffer = (char *)malloc(size);
	read(fd, buffer, size);
	return (buffer);
}
