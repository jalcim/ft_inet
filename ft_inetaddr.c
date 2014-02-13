#include <arpa/inet.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

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

unsigned long int ft_inet_addr(int value)
{
	t_in_addr addr;

	ft_inet_aton(&value, &addr);
	return(addr.s_addr);
}

int ft_inet_aton(const char *cp, t_in_addr *addr)
{
	t_aton		t;

	t.c = (char *)cp;
	t.n = 0;
	t.gotend = 0;
	while (!t.gotend)
	{
		errno = 0;
		t.val = strtoul((t.c), &(t.endptr), 0);
		if (errno == ERANGE || t.endptr == t.c)
			return (0);
		t.parts[t.n] = t.val;
		t.c = t.endptr;
		if (t.c[0] == '.')
		{
			if (t.n == 3)
				return (0);
			t.n++;
			t.c++;
		}
		else if(t.c[0] == '\0')
			t.gotend = 1;
		else
		{
			if (isspace((unsigned char)t.c[0]))
				t.gotend = 1;
			else
				return (0);
		}

	}
	if (t.n == 1)
	{
		if (t.val > 0xffffff || t.parts[0] > 0xff)
			return (0);
		t.val |= t.parts[0] << 24;
	}
	else if (t.n == 2)
	{
		if (t.val > 0xffff ||t.parts[0] > 0xff || t.parts[1] > 0xff)
			return (0);
		t.val |= (t.parts[0] << 24) | (t.parts[1] << 16);
	}
	else if (t.n == 3)
	{
		if (t.val > 0xff || t.parts[0] > 0xff || t.parts[1] > 0xff ||
				t.parts[2] > 0xff)
			return (0);
		t.val |= (t.parts[0] << 24) | (t.parts[1] << 16) | (t.parts[2] << 8);
	}
	if (addr != NULL)
		addr->s_addr = ft_htonl(t.val);
	return (1);
}
