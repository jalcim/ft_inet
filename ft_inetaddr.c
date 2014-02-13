#include <arpa/inet.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct	s_aton{
	u_long		parts[4];
	in_addr_t	val;
	char		*c;
	char		*endptr;
	int			gotend;
	int			n;
}				t_aton;

int inet_aton(const char *cp, struct in_addr *addr)
{
	t_aton		t;

	t.c = (char *)cp;
	t.n = 0;
	t.gotend = 0;
	while (!t.gotend)
	{
		t.errno = 0;
		t.val = strtoul((t.c), &(t.endptr), 0);
		if (errno == ERANGE || t.endptr == c)
			return (0);
		t.parts[t.n] = t.val;
		t.c = t.endptr;
		if (t.c[0] == '.')
		{
			if (n == 3)
				return (0);
			n++;
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
	if (n == 1)
	{
		if (val > 0xffffff || parts[0] > 0xff)
			return (0);
		val |= parts[0] << 24;
	}
	else if (n == 2)
	{
		if (val > 0xffff || parts[0] > 0xff || parts[1] > 0xff)
			return (0);
		val |= (parts[0] << 24) | (parts[1] << 16);
	}
	else if (n == 3)
	{
		if (val > 0xff || parts[0] > 0xff || parts[1] > 0xff ||
				parts[2] > 0xff)
			return (0);
		val |= (parts[0] << 24) | (parts[1] << 16) | (parts[2] << 8);
	}
	if (addr != NULL)
		addr->s_addr = htonl(val);
	return (1);
}
