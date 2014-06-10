#include "../bdd/transit_bdd.h"
#include "ft_inet.h"

int *pipe_redir(int *fd)
{
	static int *sfd = NULL;

	if (fd)
		sfd = fd;
	return (sfd);
}

void init_pipe_redir()
{
	int *pipefd;

	pipefd = (int *)malloc(2 * sizeof(int));
	pipe(pipefd);
	pipe_redir(pipefd);
}

void chat_rcv(char *login, char *buffer)
{
	init_transit(4);
	init_data(4);
	transit(login, buffer);
}

void cmd_dist_rcv(char *login, char *buffer)
{
	int *pipefd;

	printf("commande :%s: recu executer ? y/n\n", buffer);
	init_transit(2);
	init_data(2);
	pipefd = pipe_redir(NULL);
	close(pipefd[0]);
	transit(login, buffer);
	dup2(pipefd[1], 1); //redirection sortie -> pipe[1], pipe[0] -> socket
	system(buffer);//temporaire
}
