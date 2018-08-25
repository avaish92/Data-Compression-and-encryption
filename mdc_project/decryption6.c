#include "prototype.h"

int decryption6 (char * data, char * ekey)
{
	unsigned char c, d, *b;
	b = NULL;
	int fd, i, n, k;
	fd = open ("DFILE", O_WRONLY | O_CREAT);
	if (fd < 0)
	{
		perror ("open");
		exit_application ();
	}

	i = 0;
	n = 0;
	k = 0;
	while (1)
	{
		c = data[i];
		c = c >> 2;
		n = (int)c;
		c = c ^ c;
		d = d ^ d;
		if (n == 63)
		{
			break;
		}	
		b = realloc (b, k+1);
		if (b == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		b[k] = ekey[n];
		n = 0;
		k++;
		c = data[i];
		c = c << 6;
		c = c >> 2;
		i++;
		d = data[i];
		d = d >> 4;
		c = c | d;
		d = d ^ d;
		n = (int)c;
		c = c ^ c;
		if (n == 63)
		{
			break;
		}
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
		c = c >> 2;
		i++;
		d = data[i];
		d = d >> 6;
		c = c | d;
		d = d ^ d;
		n = (int)c;
		if (n == 63)
		{
			break;
		}
		b = realloc (b, k+1);
		if (b == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		b[k] = ekey[n];
		n = 0;
		k++;
		
		c = data[i];
		c = c << 2;
		c = c >> 2;
		n = (int)c;
		c = c ^ c;
		if (n == 63)
		{
			break;
		}
		b = realloc (b, k+1);
		if (b == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		b[k] = ekey[n];
		n = 0;	
		k++;
		i++;
	}
	write (fd, b, k);
	printf("The plain text has been written into the file 'DFILE'.\n");
	system ("chmod 666 DFILE");
	close (fd);
	return 0;
}
