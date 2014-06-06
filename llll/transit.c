#include "transit_bdd.h"

int transit(char *login, char *buffer)
{
	int *pipefd;
  
  if (!(pipefd = recup_pipefd(NULL)))
	  printf("error\n");
  write(pipefd[1], login, strlen(login));
  write(pipefd[1], "\0", 1);
  write(pipefd[1], buffer, strlen(buffer));
  write(pipefd[1], "\0", 1);
  return (0);
}

int print_str_struct(t_datalist *data);
void print_struct()
{
	t_datalist *data;
	int b = 1;

	printf("print_struct\n");
	data = recup_datalist(NULL);
	while (data->prev)
    {
		printf("prev\n\n"); 
		data = data->prev;
    }
	while (b)
    {
		while (print_str_struct(data))
		{}
		data->cpt_read = 0;
		if (data->next)
		{
			printf("next\n\n");
			data = data->next;
		}
		else
			b = 0;
    }
	printf("print_struct out\n");
}

int print_str_struct(t_datalist *data)
{
	if (data->cpt_read >= data->cpt_max)
		return (0);
	if (!data->login)
	{
		printf("pas d'login\n");
		exit(-1);
	}
	if (!data->data[data->cpt_read])
	{
		printf("error structure\n");
		exit(-1);
	}
	printf("login :%s: chat conv[%d] sur [%d]= :%s:\n", 
		   data->login, data->cpt_read, data->cpt_max, data->data[data->cpt_read]);
	printf(":%p:\n\n", data->data[data->cpt_read]);
	data->cpt_read++;
	return (1);
}
