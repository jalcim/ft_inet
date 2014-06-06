#include "transit_bdd.h"

char *read_line(int fd)
{
	char *tmp;
	char *buffer;
	int compt;

	compt = 0;
	tmp = (char *)malloc(2 * sizeof(char));
	bzero(tmp, 2);
	buffer = NULL;
	read(fd, tmp, 1);
	tmp[++compt] = '\0';
	while (42)
	{
		if (!buffer)
		{
			buffer = (char *)malloc(compt+2 * sizeof(char));
			strcpy(buffer, tmp);
			free(tmp);
			tmp = NULL;
			read(fd, &buffer[compt], 1);
			if (!(buffer[compt]))
				return (buffer);
			buffer[++compt] = '\0';
		}
		else
		{
			tmp = malloc(compt+2 * sizeof(char));
			strcpy(tmp, buffer);
			free(buffer);
			buffer = NULL;
			read(fd, &tmp[compt], 1);
			if (!(tmp[compt]))
				return (tmp);
			tmp[++compt] = '\0';
		}
	}
}
