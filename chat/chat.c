#include "servpipe.h"

t_conv *recup_chat(t_conv *chat)
{
  static t_conv *schat = NULL;
  int compt;

  if (!chat)
    return (schat);
  else if (chat == (t_conv *)-1 && schat)
    while (schat->next)
      {
	schat = schat->next;
	compt = -1;
	if (schat->prev)
	  {
	    while (++compt < schat->prev->cpt)
	      if (schat->prev->conv[compt])
		free(schat->prev->conv[compt]);
	    free(schat->prev->login);
	    free(schat->prev);
	    schat->prev = NULL;
	  }
      }
  else
    schat = chat;
  return (NULL);
}

t_conv *find_login(char *login, t_conv *chat)
{
  printf("find_login\n");
  if (!chat || !chat->login)
    return (NULL);
  while (chat->prev)
    chat = chat->prev;
  while (chat->next && chat->login && login && strcmp(chat->login, login))
    chat = chat->next;
  if (!(strcmp(chat->login, login)))
    return (chat);
  printf("find_login out\n");
  return (NULL);
}

void add_chain(t_conv *block);
t_conv *creat_conv(char *login)
{
  t_conv *chat;

  printf("creat_conv\n");
  if (!(chat = malloc(sizeof(t_conv))))
    error("malloc error : chat\n");
  if (!(chat->login = login))
    error("invalide login\n");
  if (!(chat->conv = malloc(sizeof(char *) * 2)))
    error("malloc error : conv\n");
  chat->conv[0] = NULL;
  chat->conv[1] = NULL;
  chat->cpt = 0;
  add_chain(chat);
  printf("conversation ajouter\n");
  return (chat);
}

void add_chain(t_conv *block)
{
  t_conv *chain;

  block->next = NULL;
  block->prev = NULL;
  if ((chain = recup_chat(NULL)))
    {
      block->next = chain;
      chain->prev = block;
    }
  recup_chat(block);
}

char **ft_repointe(char **tab1, int cpt);
void maj_conv(t_conv *chat, char *buffer)
{
  printf("maj conv\n");
  if (chat->cpt)
    chat->conv = ft_repointe(chat->conv, chat->cpt);
  chat->conv[chat->cpt] = buffer;
  chat->cpt++;
  chat->conv[chat->cpt] = NULL;
}

char **ft_repointe(char **tab1, int cpt)
{
  char **new;
  int compt;

  printf("reajustement des pointeurs cpt = %d\n", cpt);
  new = (char **)malloc((cpt * sizeof(char *)) + sizeof(char *));
  compt = 0;
  while (compt < cpt)
    {
      new[compt] = tab1[compt];
      compt++;
    }
  new[compt] = NULL;
  printf("reajustement des pointeurs out\n");
  return (new);
}
