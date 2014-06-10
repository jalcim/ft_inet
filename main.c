#include <unistd.h>
#include <stdio.h>
#include "bdd/transit_bdd.h"

void shell_server();
void print_struct();
int main()
{
  char buf;

  dup2(2, 1);
  shell_server();

  read(0, &buf, 1);
  printf("synch_data\n");

  init_transit(2);
  init_data(2);
  synch_data();
//  print_struct();
  return (0);
}
