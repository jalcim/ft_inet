#include <unistd.h>
#include <stdio.h>
#include "bdd/transit_bdd.h"

void shell_server();
void init_chat();
void start_chat();
int main()
{
  char buf;

  dup2(2, 1);
  shell_server();
  read(0, &buf, 1);
  printf("start_chat\n");
  synch_data();
  sleep(10);

  return (0);
}
