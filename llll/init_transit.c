#include "transit_bdd.h"

void init_transit(int cmd)//a appeler dans shell_server
{
  static int **pipefd = NULL;
  int cpt;

  if (!pipefd)
  {
	  printf("creation des pipes\n");
	  pipefd = (int **)malloc(4 * sizeof(int *));
	  cpt = -1;
	  while (++cpt < 4)
	  {
		  pipefd[cpt] = (int *)malloc(2 * sizeof(int));
		  pipe(pipefd[cpt]);
	  }
  }
  else if (cmd > 0)
  {
	  printf("positionnement des pipes\n");
	  recup_pipefd(pipefd[cmd-1]);
  }
  else
  {
	  printf("error pipe is allocated\n");
	  exit(-1);
  }
}

void init_data(int cmd)
{
	static t_datalist **sdata = NULL;
	static int cpt;

	if (!sdata)
	{
		printf("creation du tableau des listes\n");
		sdata = (t_datalist **)malloc(4 * sizeof(t_datalist *));
		cpt = -1;
		while (++cpt < 4)
		{
			sdata[cpt] = (t_datalist *)malloc(sizeof(t_datalist));
			sdata[cpt] = NULL;
		}
	}
	else if (cmd > 0)
	{
		printf("positionnement des listes\n");
		recup_datalist(sdata[cmd-1]);
		cpt = (cmd - 1);
	}
	else if (cmd < 0)
	{
		sdata[cpt] = recup_datalist(NULL);
	}
	else
	{
		printf("error datalist is allocated\n");
		exit(-1);
	}
}

int *recup_pipefd(int *pipefd)
{
  static int *spipefd = NULL;

  if (pipefd)
    spipefd = pipefd;
  return (spipefd);
}

t_datalist *recup_datalist(t_datalist *datalist)
{
	static t_datalist *sdatalist = NULL;

	if (!datalist)
		return (sdatalist);
	sdatalist = datalist;
	return (NULL);
}
