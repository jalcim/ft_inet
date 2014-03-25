/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock_in_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 04:45:51 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/25 22:45:20 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_inet.h"
#include <stdio.h>

void ft_send_dir(int socket, char *name_dir)
{
	static int flag = 0;
    int nb;
    char *nb_file;
	DIR *rep;
	t_dirent *Rfille = NULL;

	ft_putendl("ft_send_dir");
//	ft_putendl(name_dir);
//	ft_putstr_fd(name_dir, socket);
//  write(socket, "\0", 1);
	nb = ft_compt_dir(name_dir);
	ft_putendl("ftir");
	nb_file = ft_itoa(nb);

	ft_printf("open :%s:\n", name_dir);
	if (!(rep = opendir(name_dir)))
		error("opendir -> ");
	chdir(name_dir);

	ft_printf("/!\\send name_dir = :%s:\n", name_dir);
	if (flag)
	{
		while ((Rfille = readdir(rep)) && Rfille->d_name[0] == '.')
			if (Rfille == NULL)
				error("readdir -> ");

		write(socket, "1", 1);//dossier
		ft_putendl("SIGDIR");

		write(socket, nb_file, ft_strlen(nb_file));
		write(socket, "\0", 1);
		ft_send_file(socket, Rfille->d_name, --nb, &rep);
	}
	else
	{
		flag = 1;
		write(socket, nb_file, ft_strlen(nb_file));
		write(socket, "\0", 1);
		ft_printf("nb = %d = :%s:\n", nb, nb_file);
		ft_send_file(socket, name_dir, nb, &rep);
	}
	closedir(rep); 
	chdir("..");
}

void ft_send_file(int socket, char *filename, int nb, DIR **rep)//[rep]
{
	static int first = 1;
	t_dirent *Rfille = NULL;
	int fd;
	char ok;

	ft_putendl("empile");
	if (nb >= 0)
	{
		ft_printf("filename -> sock = :%s:\n", filename);
		ft_putstr_fd(filename, socket);
		write(socket, "\0", 1);
	}
	if (ft_is_dir(filename) && !first)// || (first && nb >= 0))
	{
		ft_putendl("send dir");
		nb--;
		ft_send_dir(socket, filename);
	}
	else if ((fd = open(filename, O_RDONLY, S_IRUSR)) && ((!first && nb >= 0) || (first && !nb)))
	{
		ft_printf("send file = :%s:\n", filename);
		if (!fd)
			error("open ->");
		write(socket, "0", 1);//fichier
		
		ft_sendfile(fd, socket);//ft_sock_in_file(fd, socket)
		ft_putendl("sconfirmation ?");
		read(socket, &ok, 1);//attente de confirmation
		ft_putendl("sconfirmation !");
	}
	else
	{
/*[]*/	if (first)
		{
			ft_putendl("premier dossier");
			first = 0;
		}
		else if (nb)
			error("sbad request -> ");
		else if (!nb)
		{
			ft_printf("by\n");
			return ;
		}
	}
	printf("rrrrrr = %d\n", nb);
	if (nb > 0)
	{
		ft_putendl("relance");
		while ((Rfille = readdir((*rep))) && Rfille->d_name[0] == '.')
			if (Rfille == NULL)
				error("readdir -> ");
		if (Rfille->d_name == (char *)0x15)
			return ;
		ft_printf("nb = :%d:\n", nb);
		printf("sfilename repere = :%p:\n", Rfille->d_name);
		ft_putendl("re");
		if ((nb - 1))
/*[]*/		nb--;
		return (ft_send_file(socket, Rfille->d_name, nb, rep));
		ft_putendl("depile");
	}
	ft_printf("bby\n");
	return ;
}

int ft_recv_file(int socket, int nb)
{
	static char first = -1;
	int fd;
	char *filename;

	sleep(1);
	ft_putendl("empile");
	ft_printf("nb = :%d:\n", nb);
	write(1, "?????\n", 6);
	filename = ft_recv_filename(socket);
	printf("{%s}\n", filename);
	if (first != -1 || !nb)//pas le premier tour ou pas un dossier(/!\ou plus de fichier)
		read(socket, &first, 1);//[mode]
	else
	{
		first = 0;
		ft_putendl("premier dossier");
		mkdir(filename, 0777);

		char *pwd = ft_strnew(100);
		getcwd(pwd, 100);
		ft_printf("____\npwd = :%s:\n----\n", pwd);
		chdir(filename);
		getcwd(pwd, 100);
		ft_printf("____\npwd = :%s:\n----\n", pwd);

		free(pwd);
		return (ft_recv_file(socket, nb));
	}
	write(1, "-->", 3);//
	write(1, &first, 1);
	write(1, "|\n", 2);
	first -= '0';//[dossier ou fichier ?]
	if (first && nb)
	{
		ft_printf("dir = :%s:\n", filename);
		mkdir(filename, 0777);
		chdir(filename);
		ft_recv_file(socket, nb_dir_sock(socket));
		ft_putendl("-----\ndepile\n--------\n");
		chdir("..");
	}
	else if ((!first || !nb) && (fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)))
	{
		ft_printf("recv file = :%s:\n", filename);
		free(filename);
		if (!fd)
			error("open -> ");

		ft_putendl("reception\n");
		ft_recvfile(socket, fd);
		ft_putendl("cconfirmation ?");
		write(socket, "0", 1);//donc confirmation
		ft_putendl("cconfirmation !");
	}
	first = 0;
	if (nb && --nb)
	{
		ft_putendl("vrai");
		first = ft_recv_file(socket, nb);
	}
	return (1);
}

static void ft_fusion(char **buffer, char *tmp);
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
            ft_fusion(&buffer, tmp);
			ft_bzero(tmp, 1024);
            compt = -1;
        }
    }
    tmp[compt] = '\0';
    ft_fusion(&buffer, tmp);
    free(tmp);
    return (buffer);
}

static void ft_fusion(char **buffer, char *tmp)
{
    if (!((*buffer) = (char *)realloc((*buffer), (ft_strlen((*buffer)) + ft_strlen(tmp)) + 1)))
        error("realloc ->");
    ft_strcat((*buffer), tmp);
}

char *ft_recv_filename(int sock)
{
    char *filename;
    int compt;

    filename = ft_strnew(256);
    compt = -1;
	ft_putendl("recv_filename");
    while (read(sock, &filename[++compt], 1) && filename[compt] != '\0' && compt < 255)
		write(1, &filename[compt], 1);
	ft_putstr("\nend read filename\n");
    if (filename[compt] != '\0')
    {
        printf("invalide filename :%s:\n", filename);
        exit(0);
    }
    return (filename);
}

int ft_is_dir(char *name)
{
	DIR *tmp;
	if ((tmp = opendir(name)))
	{
		closedir(tmp);
		return (1);
	}
	return (0);
}

int ft_compt_dir(char *namedir)
{
	DIR *rep;
    t_dirent *Rfille;
    int compt;

    compt = 0;
	ft_putendl("ft_compt_dir");
	ft_printf("open %s\n", namedir);
    if (((rep) = opendir(namedir)))
	{
		while ((Rfille = readdir(rep)))
			if (Rfille->d_name[0] != '.')
				compt++;
	}
	else
		error("opendir -> ");
	ft_putendl("close");
	closedir(rep);
    return (compt);
}

int nb_dir_sock(int sock)
{
    char nb_dir[255];
    int compt;

    compt = -1;
    while (compt <= 255 && read(sock, &nb_dir[++compt], 1) && nb_dir[compt] != '\0')
        ;
    if (nb_dir[compt] != '\0')
        return (0);
	ft_putstr("nb = ");
	ft_putendl(nb_dir);
    return (atoi(nb_dir));
}
