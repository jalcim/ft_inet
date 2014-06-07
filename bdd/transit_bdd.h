#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

typedef struct s_datalist t_datalist;

struct s_datalist
{
  char *login;
  char **data;
  int cpt_read;
  int cpt_max;

  t_datalist *prev;
  t_datalist *next;
};

void init_transit(int cmd);
int *recup_pipefd(int *pipefd);

void init_data(int cmd);
t_datalist *recup_datalist(t_datalist *datalist);

int transit(char *login, char *buffer);
void synch_data();
void gest(char *login, char *buffer);
t_datalist *find_login(char *login, t_datalist *data);
t_datalist *creat_datalist(char *login);
void add_chain(t_datalist *block);

int fd_size(int fd);
char *read_line(int fd);
