#include "transit_bdd.h"

void print_struct();
int main()
{
	init_transit(0);
	init_transit(4);
	init_data(0);
	init_data(4);

	int boll = 0;

	goto nd;
re:
	init_transit(2);	
	init_data(2);
	boll = 1;
	sleep(5);
nd:
	if (!fork())
    {
		transit("jalcim", "test 0");
		transit("jalcim", "test 1");
		transit("jalcim", "test 2");
		transit("jalcim", "test 3");
		transit("jalcim", "test 4");
		transit("jalcim", "test 5");
		transit("jalcim", "test 6");
		transit("jalcim", "test 7");
		transit("jalcim", "test 8");
		transit("jalcim", "test 9");

		transit("jalcim", "test 10");
		transit("jalcim", "test 11");
		transit("jalcim", "test 12");
		transit("jalcim", "test 13");
		transit("jalcim", "test 14");
		transit("jalcim", "test 15");
		transit("jalcim", "test 16");
		transit("jalcim", "test 17");
		transit("jalcim", "test 18");
		transit("jalcim", "test 19");

		transit("GRUM", "test 20");
		transit("GRUM", "test 21");
		transit("GRUM", "test 22");
		transit("GRUM", "test 23");
		transit("GRUM", "test 24");
		transit("GRUM", "test 25");
		transit("GRUM", "test 26");
		transit("GRUM", "test 27");
		transit("GRUM", "test 28");
		transit("GRUM", "test 29");

		transit("GRIIIM", "test 30");
		transit("GRIIIM", "test 31");
		transit("GRIIIM", "test 32");
		transit("GRIIIM", "test 33");
		transit("GRIIIM", "test 34");
		transit("GRIIIM", "test 35");
		transit("GRIIIM", "test 36");
		transit("GRIIIM", "test 37");
		transit("GRIIIM", "test 38");
		transit("GRIIIM", "test 39");

		transit("jalci", "test 40");
		transit("jalci", "test 41");
		transit("jalci", "test 42");
		transit("jalci", "test 43");
		transit("jalcm", "test 44");
		transit("jalcm", "test 45");
		transit("jalcm", "test 46");
		transit("jalci", "test 47");
		transit("jalcim", "test 48");
		transit("jalcim", "test 49");
		exit(0);
    }
	sleep(1);
  synch_data();
  printf("ok\n");
  sleep(2);
  print_struct();
  if (!boll)
	  goto re;
  return (0);
}
