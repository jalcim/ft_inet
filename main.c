#include <unistd.h>
#include <stdio.h>
#include "bdd/transit_bdd.h"

void shell_server();
int main()
{
  char buf;

  dup2(2, 1);
  shell_server();
  read(0, &buf, 1);
  printf("synch_data\n");
//
  init_transit(4);
  init_data(4);
  synch_data();
  system("killall server");
  return (0);
}
