/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servcom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 01:07:00 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/28 13:08:45 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_inet.h"
#include "../libft/libft.h"

//partie shell
void shell_server()
{
	int pid;
	int fifo[2];

	if (!(pid = fork()))
		return ;//pere retourne au shell

	pipe(fifo);
	recup_pipe(fifo);

	if (!(pid = fork()))
		wait_sig();//fils du fils devien processus communiquation coter shell
	servershell(pid);//fils devien pere du server
}

void wait_sig()
{
	int pid;

	signal(SIGUSR1, sig_serv);
	signal(SIGUSR2, sig_serv);

//	if (!(pid = fork()))
	write(1, "wait\n", 5);
	pause();
	printf("fin de transmition\n");
//	wait_sig();
	exit(0);
}

void sig_serv(int sig)
{
	int *fifo;
	char *buffer;

	fifo = recup_pipe(NULL);
	close(fifo[1]);
	buffer = ft_fd_in_str(fifo[0]);//lecture_pipe dans buffer;
	printf("buffer sig_serv = :%s:\n", buffer);
	if (sig == SIGUSR1)//si c'est un chat
		printf("fonction_chat_minishell(buffer);\n");//fonction_chat_minishell(buffer);
	else if (sig == SIGUSR2)//si c'est une commande
		printf("fonction_de_traitement(buffer);\n");//fonction_de_traitement(buffer);
	free(buffer);
}

//partie server
void servcom(char mode, char *buffer, int pid)
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
	ft_putstr_fd((buffer), fifo[1]);//transmition
}

int *recup_pipe(int *fifo)
{
	static int *fifo_save = NULL;

	if (fifo)
		fifo_save = fifo;
	else
	{
		if (fifo_save == NULL)
			return (NULL);
		return (fifo_save);
	}
	return (NULL);
}