#include <sys/types.h>
#include <sys/stat.h>
#include "servpipe.h"

int size_fd(int fd)
{
  struct stat status;

  fstat(fd, &status);

  return (status.st_size);
}

static void ft_fusion(char **buffer, char *tmp);
char *ft_fd_in_str(int fd)
{
    char *tmp;
    char *buffer;
    int compt;

    write(1, "ft_fd_in_str\n", 13);
    compt = -1;
    tmp = malloc(1024);
    buffer = malloc(1);
    buffer[0] = '\0';
    while (read(fd, &tmp[++compt], 1) > 0 && tmp[compt] != '\0')
      if (compt == 1022)
	{
	  tmp[compt + 1] = '\0';
	  ft_fusion(&buffer, tmp);
	  bzero(tmp, 1024);
	  compt = -1;
        }
    tmp[compt] = '\0';
    ft_fusion(&buffer, tmp);
    free(tmp);
    return (buffer);
}

static void ft_fusion(char **buffer, char *tmp)
{
    if (!((*buffer) = (char *)realloc((*buffer), (strlen((*buffer)) + strlen(tmp)) + 1)))
        error("realloc ->");
    strcat((*buffer), tmp);
}
