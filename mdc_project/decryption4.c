#include "prototype.h"

int decryption4 (char * data, char * ekey)
{
	unsigned char c;
	char * d;
	d = NULL;
	int i, n = 0, k;
	i = 0;
	k = 0;
	while (1)
	{
		c = data[i];	
		c = c >> 4;
		if(c == 15)
		{
			break;
		}
		n = (int)c;
		
		d = realloc(d, k+1);
		if (d == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		d[k] = ekey[n];
		k++;		
		
		c = data[i];
		c = c << 4;
		c = c >> 4;
		if(c == 15)
		{
			break;
		}
		n = (int)c;

		d = realloc(d, k+1);
		if (d == NULL)
		{
			perror ("realloc");
			exit_application ();
		}
		d[k] = ekey[n];
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
	printf("The plain text has been successfully written in the file 'DFILE'.\n");
	system ("chmod 666 DFILE");
	close (fd);
	return 0;
}

