#include "prototype.h"

int decryption3 (char * data, char * ekey)
{
	unsigned char c, d;
	char * b;
	b = NULL;
	int i, k, n;
	k = 0;
	i = 0;
	n = 0;
	while(1)
	{
		c = c ^ c;
		d = d ^ d;
		c = data[i];
		c = c >> 5;
		n = (int)c;
		c = c ^ c;
		if (n == 7)
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
		c = c << 3;
		c = c >> 5;
		n = (int)c;
		c = c ^ c;
		if (n == 7)
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
		c = c >> 5;
		i++;
		d = data[i];
		d = d >> 7;
		c = c | d;
		d = d ^ d;
		n = (int)c;
		c = c ^ c;
		if (n == 7)	
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
		c = c << 1;
		c = c >> 5;
		n = (int)c;
		c = c ^ c;
		if (n == 7)
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
		c = c << 4;
		c = c >> 5;
		n = (int)c;
		c = c ^ c;
		if (n == 7)
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
		c = c << 7;
		c = c >> 5;
		i++;
		d = data[i];
		d = d >> 6;
		c = c | d;
		d = d ^ d;
		n = (int)c;
		c = c ^ c;
		if (n == 7)
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
		c = c >> 5;
		n = (int)c;
		c = c ^ c;
		if (n == 7)
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
		c = c << 5;
		c = c >> 5;
		n = (int)c;
		c = c ^ c;
		if (n == 7)
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
	int fd;
	fd = open ("DFILE", O_WRONLY | O_CREAT);
	if (fd < 0)
	{
		perror ("open");
		exit_application ();
	}

	write (fd, b, k);
	printf("The plain text is successfully written in the file 'DFILE'.\n");
	system ("chmod 666 DFILE");
	close (fd);
	return 0;
}
