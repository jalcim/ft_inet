/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servcom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 01:07:00 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/27 02:34:27 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_inet.h"
#include "../libft/includes/libft.h"

/* partie shell
   pere retourne au shell
   fils du fils devien processus communiquation coter shell
   fils devien pere du server
   SIGUSR1 == chat
   SIGUSR2 == cmd
*/
t_server	*recup(t_server *server);
int         chat(char *login, char *b);
//int         ft_distcmd(char *login, char *line);

void shell_server()
{
  int pidp;
  int pid;
  int *fifo;

  if (!(fifo = (int *)malloc(2*sizeof(int))))
    error("malloc error\n");
  pidp = getpid();
  if ((pid = fork()))
    {
      ft_pidsave(pid);
      return ;
    }
    pipe(fifo);
    recup_pipe(fifo);
    if (!(pid = fork()))
      {
	ft_pidsave(pidp);
	wait_sig();
      }
    ft_pidsave(pid);
    signal(SIGINT, killslave);
    servershell(pid);
}

void wait_sig()
{
    signal(SIGUSR1, sig_serv);
    signal(SIGUSR2, sig_serv);

    while (1)
        pause();
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
    user = ft_fd_in_str(fifo[0]);
    buffer = ft_fd_in_str(fifo[0]);
    if (sig == SIGUSR1)
      chat(user, buffer);
    else if (sig == SIGUSR2)
      ft_putstr("distcmd\n");
      //      if (ft_distcmd(user, buffer))
      //ft_putstr("commande failled\n");
    close(fifo[0]);
    free(buffer);
    free(user);
}

/* partie server */
void servcom(char mode, char *user, char *buffer, int pid)
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
        ft_putstr("argument not valide\n");
		exit(0);
    }
    ft_putstr_fd(user, fifo[1]);
    write(fifo[1], "\0", 1);
    ft_putstr_fd(buffer, fifo[1]);
    write(fifo[1], "\0", 1);
}

void killslave()
{
	t_server *server;
    int pid;

    pid = ft_pidsave(0);
    kill(pid, SIGINT);
	server = recup(NULL);
	close(server->sock);
    free(server->client);
    free(server);
    exit(0);
}

int ft_pidsave(int pid)
{
    static int spid = 0;

    if (pid)
        spid = pid;
    else
        return (spid);
    return (0);
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
