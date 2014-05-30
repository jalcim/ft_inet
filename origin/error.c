#include <stdio.h>
#include <stdlib.h>

void error(char *str)
{
  perror(str);
  exit(-1);
}
