#include "transit_bdd.h"

void synch_data()//a appeler dans l'interface chat et dans une fonction de securiter
{
  int *pipefd;
  char *login;
  char *buffer;

  int size;

  pipefd = recup_pipefd(NULL);
  while ((size = fd_size(pipefd[0])))
    {
      login = read_line(pipefd[0]);
      buffer = read_line(pipefd[0]);
	  printf("login == :%s:\n", login);
	  printf("buffer == :%s:\n\n", buffer);
      gest(login, buffer);
   }
}

void gest(char *login, char *buffer)
{
  t_datalist *datalist;

  datalist = recup_datalist(NULL);
  if ((datalist = find_login(login, datalist)))
    printf("chat trouver\n");
  else
  {
	  datalist = creat_datalist(login);
      printf("chat creer\n");
  }
  datalist->data[datalist->cpt_max] = buffer;
  datalist->cpt_max++;
}

t_datalist *find_login(char *login, t_datalist *data)
{
	if (!(data && data->login))
		return (NULL);
	while (data->prev)
		data = data->prev;
	while (strcmp(login, data->login) && data->next)
		data = data->next;
	if (!(strcmp(login, data->login)))
		return (data);
	return (NULL);
}


t_datalist *creat_datalist(char *login)
{
	t_datalist *data;
	
	data = (t_datalist *)malloc(sizeof(t_datalist));
	data->data = (char **)malloc(100 * sizeof(char *));
	data->login = login;
	data->data[0] = NULL;
	data->cpt_read = 0;
	data->cpt_max = 0;
	add_chain(data);
	recup_datalist(data);
	init_data(-1);
	return (data);
}

void add_chain(t_datalist *block)
{
	t_datalist *chain;
	
	block->next = NULL;
	block->prev = NULL;
	if ((chain = recup_datalist(NULL)))
    {
		block->next = chain;
		chain->prev = block;
    }
}
