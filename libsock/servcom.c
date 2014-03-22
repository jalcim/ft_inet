/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servcom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 01:07:00 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/22 13:24:14 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_inet.h"
#include "../libft/libft.h"
#include <signal.h>

//partie shell
void shell_server()
{
	int pid;
	int fifo[2];

	if ((pid = fork()))
		return ;//pere retourne au shell

	pipe(fifo);
	recup_pipe(fifo);

	if (!(pid = fork()))
		wait_sig();//fils du fils devien processus communiquation coter shell
	servershell(pid);//fils devien pere du server
}

void wait_sig()
{
	signal(SIGUSR1, sig_serv);
	signal(SIGUSR2, sig_serv);

	while (1)
	{
		write(1, "wait_sig\n", 9);
		pause();
		write(1, "end_sig\n", 8);
	}
}

void sig_serv(int sig)
{
	char *buffer;
	char *user;
	int *fifo;
	int pid;

	if ((pid = fork()))
		return ;
	fifo = recup_pipe(NULL);
	close(fifo[1]);
	user = ft_fd_in_str(fifo[0]);//[user]
	buffer = ft_fd_in_str(fifo[0]);//lecture_pipe dans buffer;
	printf("login %s\n", user);//[user]
	printf("commande sig_serv = :%s:\n", buffer);
	if (sig == SIGUSR1)//si c'est un chat
		ft_putstr("fonction_chat_minishell(user, buffer);\n");//fonction_chat_minishell(user, buffer);
	else if (sig == SIGUSR2)//si c'est une commande
		ft_putstr("fonction_de_traitement(user, buffer);\n");//fonction_de_traitement(user, buffer);

	free(buffer);//
	write(1, "fin de transmition\n", 19);//
	exit(0);//
}

//partie server
void servcom(char mode, char *user, char *buffer, int pid)//[user]
{
	int *fifo;

	fifo = recup_pipe(NULL);
	close(fifo[0]);
	if (mode == 'c')
		kill(pid, SIGUSR1);
	else if (mode == 'x')
		kill(pid, SIGUSR2);
	else
	{
		printf("argument not valide\n");
		exit(0);
	}
	ft_putstr_fd(user, fifo[1]);//[user]
	write(fifo[1], "\0", 1);
	ft_putstr_fd(buffer, fifo[1]);//transmition
	write(fifo[1], "\0", 1);
}

int *recup_pipe(int *fifo)
{
	static int *fifo_save = NULL;

	if (fifo)
		fifo_save = fifo;
	else
		return (fifo_save);
	return (NULL);
}

