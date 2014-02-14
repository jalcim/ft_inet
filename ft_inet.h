#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>

typedef struct sockaddr_in t_sockaddr_in;
typedef struct in_addr t_in_addr;
typedef struct pollfd t_pollfd;
typedef struct sockaddr t_sockaddr;
typedef struct	s_aton t_aton;

struct	s_aton
{
	u_long		parts[4];
	in_addr_t	val;
	char		*c;
	char		*endptr;
	int			gotend;
	int			n;
};

unsigned long int ft_inet_addr(int value);
int ft_inet_aton(const char *cp, struct in_addr *addr);
unsigned short ft_htons(unsigned short value);
unsigned int ft_htonl(unsigned int value);
void error();
