#include "../bdd/transit_bdd.h"

void chat_rcv(char *login, char *buffer)
{
	init_transit(4);
	init_data(4);
	transit(login, buffer);
}

void cmd_dist_rcv(char *login, char *buffer)
{
	init_transit(2);
	init_data(2);
//	dup2(socket, 1); //haha les chose interessante commence ^^
	transit(login, buffer);
	system(buffer);//temporaire
}
