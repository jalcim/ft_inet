#ifndef __servpipe__
#define __servpipe__
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libsock/ft_inet.h"
#include "libft/includes/libft.h"

typedef struct s_conv t_conv;

struct s_conv
{
  char *login;
  char **conv;
  int cpt;
  int cpt_read;

  t_conv *next;
  t_conv *prev;
};

void error(char *strerr);
int *recup_pipe(int *fd);
t_conv *recup_chat(t_conv *chat);
void init_chat();
void maj_conv(t_conv *chat, char *buffer);
t_conv *creat_conv(char *login);
t_conv *find_login(char *login, t_conv *chat);
void start_chat();
int chat(char *login, char *buffer);
int size_fd(int fd);

#endif
