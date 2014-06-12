#include "../libft/includes/libft.h"
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

	ft_putstr_fd(login, 2);
	ft_putstr_fd(" lance la commande :", 2);
	ft_putstr_fd(buffer, 2);
	ft_putstr_fd(": recu executer ? y/n\n", 2);

	init_transit(2);
	init_data(2);
	transit(login, buffer);

	if (!(pipefd = pipe_redir(NULL)))
		error("pipe not found");
	if (pipefd[0] != 13 || pipefd[1] != 14)
		ft_putstr_fd("change\n", 2);
	close(pipefd[0]);
//	dup2(pipefd[1], 1); //redirection sortie -> pipe

	write(2, "write\n", 6);
	write(pipefd[1], "hello\0", 6);

//	system(buffer);//temporaire
}
