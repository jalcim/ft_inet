#include "servpipe.h"

void init_chat()
{
  int *pipefd;

  if (!(pipefd = (int *)malloc(2*sizeof(int))))
    error("malloc error\n");
  pipe(pipefd);
  recup_pipefd(pipefd);
}

int *recup_pipefd(int *pipe)
{
  static int *s_pipe = NULL;

  if (!pipe)
    {
      printf("recup_pipe ret\n");
      return (s_pipe);
    }
  else if (pipe != (int *)-1)
    {
      printf("recup_pipe reg\n");
      s_pipe = pipe;
    }
  else
    if (s_pipe)
      {
	printf("recup_pipe free\n");
	close(s_pipe[0]);
	close(s_pipe[1]);
	free(s_pipe);
      } 
  return (NULL);
}
