#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void emmetteur(int pid, int cmd);
void recepteur();

void ft_sig1();
void ft_sig2();
void ft_calcul(int nb);

int sv_pid(int pid);
int *sv_pip(int *pipe);
int *cmd_pipe(int cmd);

void ok();

int main()
{
	int pid;

	sv_pid(getpid());
	if (pid = fork())
		emmetteur(pid, 1);
	else
		recepteur();

}

int *sv_pip(int *pipe)
{
	static int *spipe = NULL;

	if (pipe == (int *) -1)
		;
	else if (pipe)
		spipe = pipe;
	else
		return (spipe);
	return (NULL);
}

int sv_pid(int pid)
{
	static int spid = NULL;

	if (pid == -1)
		;
	else if (pid)
		spid = pid;
	else
		return (spid);
	return (0);
}

void ok()
{
	return ;
}

void emmetteur(int pid, int cmd)
{
	signal(SIGUSR1, ok);
	sleep(1);
	while (cmd > 0 && cmd < 5)
	{
		if (cmd == 1 || cmd == 3)
		{
			cmd -= 2;
			kill(pid, SIGUSR1);		
		}
		else if (cmd == 2 || cmd == 4)
		{
			cmd -= 2;
			kill(pid, SIGUSR2);
		}
		pause();
	}
}

void recepteur()
{
	signal(SIGUSR1, ft_sig1);
	signal(SIGUSR2, ft_sig2);
	while (42)
	{
		pause();
		write(2, "aaaaaaaa\n", 9);
		kill(sv_pid(0), SIGUSR1);
	}
}

int *cmd_pipe(int cmd)
{
	static int **sdpipe = NULL;
	int cpt;

	if (cmd == 0)
	{
		sdpipe = (int **)malloc(4 * sizeof(int *));
		cpt = -1;
		while (++cpt)
		{
			sdpipe[cpt] = (int *)malloc(sizeof(int));
			pipe(sdpipe[cpt]);
		}
	}

//	if (cmd == )
}

void ft_sig1()
{
//	write(2, "aaaaaaaa\n", 9);
	ft_calcul(1);
}

void ft_sig2()
{
//	write(2, "aaaaaaaa\n", 9);
	ft_calcul(2);
}

void ft_calcul(int nb)
{
	static int cmd = 0;

	if (cmd == 1 && nb == 1)
		printf(" cmd send \n");
	else if (cmd == 1 && nb == 2)
		printf(" cmd recev \n");
	else if (cmd == 2 && nb == 1)
		printf(" chat send \n");
	else if (cmd == 2 && nb == 2)
		printf(" chat recev \n");
	else if (cmd == 0 && nb)
	{
		cmd = nb;
		return ;
	}
	cmd = 0;
}
