#include "prototype.h"

char * read_file (char * b)
{
	int fd,count, i;
	char * a, ch;	
	fd = open (b, O_RDONLY);
	if (fd < 0)
	{
		perror ("open");
	}
	else
	{
		printf ("\n'%s' is opened successfully on the file descripter : %d\n", b, fd);
	}
	
	count = 1;	
	i = 0;
	a = NULL;
	while (count)
	{
		count = read (fd, &ch, 1);
		a = (char *) realloc (a, i+1); 
		if (a == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		else 
		{
			a[i] = ch;
			i++;
		}
	}
	a[i] = '\0';
	close (fd);
	return a;
}
