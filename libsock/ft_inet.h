#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "sys/stat.h"
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <poll.h>

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

unsigned long int ft_inet_addr(const char *ip);
int ft_inet_aton(const char *cp, struct in_addr *addr);
unsigned short ft_htons(unsigned short value);
unsigned int ft_htonl(unsigned int value);

int ft_fd_in_str(int fd, char *buffer);
void ft_sock_in_file(int socket, int fd);
void ft_file_in_sock(int fd, int socket);
void ft_recv_file(int socket, char *filename);
void ft_send_file(int socket, char *filename);

void ft_socktcp(int *sock, int port, t_sockaddr_in *serveur);
void ft_waitsocktcp(int sock, t_pollfd *event, int size_fille, int time);

void error();
