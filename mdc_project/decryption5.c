#include "prototype.h"

int decryption5 (char * data, char * ekey)
{
	unsigned char c, b;
	char * d;
	d = NULL;
	int i, n = 0, k;
	i = 0;
	k = 0;
	while (1)
	{
		b = b ^ b;
		c = c ^ c;
		c = data[i];
		c = c >> 3;
		if (c == 31)
	 	{
			break;
		}

		d = realloc (d, k+1);
		if (d == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		n = (int)c;
		d[k] = ekey[n];
		n = 0;
		k++;
		c = c ^ c;
		
		c = data[i];
		c = c << 5;
		c = c >> 3;
		i++;
		b = data[i];
		b = b >> 6;
		c = c | b;
		b ^= b; 
		if (c == 31)
	 	{
			break;
		}
		d = realloc (d, k+1);
		if (d == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		n = (int)c;
		d[k] = ekey[n];
		n = 0;
		k++;
		c = c ^ c;
		
		c = data[i];
		c = c << 2;
		c = c >> 3;
		if (c == 31)
	 	{
			break;
		}
		d = realloc (d, k+1);
		if (d == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		n = (int)c;
		d[k] = ekey[n];
		n = 0;
		k++;
		c = c ^ c;
		
		c = data[i];
		c = c << 7;
		c = c >> 3;
		i++;
		b = data[i];
		b = b >> 4;
		c = c | b;
		b ^= b;
		if (c == 31)
	 	{
			break;
		}
		d = realloc (d, k+1);
		if (d == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		n = (int)c;
		d[k] = ekey[n];
		n = 0;
		k++;
		c = c ^ c;
		
		c = data[i];
		c = c << 4;
		i++;
		b = data[i];
		c = c >> 3;
		b = b >> 7;
		c = c | b;
		b = b ^ b;
		if (c == 31)
	 	{
			break;
		}
		d = realloc (d, k+1);
		if (d == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		n = (int)c;
		d[k] = ekey[n];
		n = 0;
		k++;
		c = c ^ c;
		c = data[i];
		c = c << 1;	
		c = c >> 3;
		if (c == 31)
	 	{
			break;
		}
		d = realloc (d, k+1);
		if (d == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		n = (int)c;
		d[k] = ekey[n];
		n = 0;
		k++;
		c = c ^ c;
		c = data[i];
		c = c << 6;
		c = c >> 3;
		i++;
		b = data[i];
		b = b >> 5;
		c = c | b;
		b = b ^ b;
		if (c == 31)
	 	{
			break;
		}
		d = realloc (d, k+1);
		if (d == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		n = (int)c;
		d[k] = ekey[n];
		n = 0;
		k++;
		c = c ^ c;
		c = data[i];
		c = c << 3;
		c = c >> 3;
		if (c == 31)
	 	{
			break;
		}
		d = realloc (d, k+1);
		if (d == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		n = (int)c;
		d[k] = ekey[n];
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
	write (fd, d, k);
	printf("The plain text is successfully written in the file 'DFILE'.\n");
	system ("chmod 666 DFILE");
	close (fd);
	return 0;
}
