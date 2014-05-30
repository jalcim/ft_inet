#include "servpipe.h"

int chat(char *login, char *buffer)
{
  int *fd;

  if (!(fd = recup_pipe(NULL)))
    return (-1);
  printf("ecriture de la part de :%s: message :%s:\n",login, buffer);
  write(fd[1], login, strlen(login));
  write(fd[1], "\0", 1);
  write(fd[1], buffer, strlen(buffer));
  write(fd[1], "\0", 1);
  return (0);
}

void start_chat()
{
  int *fd;
  t_conv *chat;
  char *buffer;
  char *login;

  login = NULL;
  buffer = NULL;
  printf("start_chat\n");
  chat = recup_chat(NULL);
    if (chat)
      printf("chat recup\n");
  fd = recup_pipe(NULL);
  while (size_fd(fd[0]))
    {
      if ((!(login = ft_fd_in_str(fd[0])))
	  || (!(buffer = ft_fd_in_str(fd[0]))))
	break;
      printf("lecture de la part de :%s: message :%s:\n",login, buffer);
      if ((chat = find_login(login, chat)))
	printf("chat trouver\n");
      else
	{
	  chat = creat_conv(login);
	  printf("chat creer\n");
	}
      maj_conv(chat, buffer);
    }
}/*
  //end
  while (chat->prev)
    chat = chat->prev;
  int i = 0;
  int b = 1;
  while (b)
    {
      while (i < chat->cpt)
	{
	  printf("%s envoie de :%s:\n\n\n\n", chat->login, chat->conv[i]);
	  i++;
	}
      i = 0;
      if (chat->next)
	chat = chat->next;
      else
	b = 0;
    }
  printf("exit\n");
}*/
