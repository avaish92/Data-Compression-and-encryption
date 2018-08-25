#include "prototype.h"

int decryption2 (char * data, char * ekey)
{
	unsigned char c, *b;
	b = NULL;
	int fd, i, k, n;
	fd = open ("DFILE", O_WRONLY | O_CREAT);
	if (fd < 0)
	{
		perror ("open");
		exit_application ();
	}
	i = 0;
	k = 0;
	n = 0;
	while (1)
	{
		c = data[i];
		c = c >> 6;
		if (c == 3)
		{
			break;
		} 
		n = (int)c;
		c = c ^ c;
		b = realloc (b, k+1);
		if (b == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		b[k] = ekey[n];
		k++;
		n = 0;
		c = data[i];
		c = c << 2;
		c = c >> 6;
		if (c == 3)
		{
			break;
		}
		n = (int)c;
		c = c ^ c;
		b = realloc (b, k+1);
		if (b == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		b[k] = ekey[n];
		k++;
		n = 0;
		c = data[i];
		c = c << 4;
		c = c >> 6;
		if (c == 3)
		{
			break;
		} 
		n = (int)c;
		c = c ^ c;
		b = realloc (b, k+1);
		if (b == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		b[k] = ekey[n];
		k++;
		n = 0;
		c = data[i];
		c = c << 6;	
		c = c >> 6;
		if (c == 3)
		{
			break;
		} 
		n = (int)c;
		c = c ^ c;
		b = realloc (b, k+1);
		if (b == NULL)
		{
			perror("realloc");
			exit_application ();
		}
		b[k] = ekey[n];
		n = 0;
		k++;
		
		i++;
	}
	write (fd, b, k);
	printf("The plain text is successfully written in file 'DFILE'\n");
	system ("chmod 666 DFILE");
	close (fd);
	return 0;
}
