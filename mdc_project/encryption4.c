#include "prototype.h"

int encryption4 (char * a, char * ekey)
{
	unsigned char c, byt;
	int i, n = 0;
	
	int fd;
	fd = open ("CFILE", O_WRONLY | O_CREAT);
	if(fd < 0)
	{
		perror ("open");
		exit_application ();
	}	
	i = 0;
	while (1)
	{
		byt = byt ^ byt;
		n = find_index (a[i], ekey);
		//sprintf(&c, "%d", n);
		c = (unsigned char)n;
		c = c << 4;
		byt = byt | c;
		c ^= c;
		i++;
		if (a[i] == '\0')
		{
			c = 15;
			c = c << 4;
			c = c >> 4;
			byt = byt | c;		
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		} 
		n = find_index (a[i], ekey);
		//sprintf(&c, "%d", n);
		c = (unsigned char)n;
		c = c << 4;
		c = c >> 4;
		byt = byt | c;
		c ^= c;
		write (fd, &byt, 1);
		byt ^= byt;
		i++;
		
		if(a[i] == '\0')
		{
			c = 15;
			c = c << 4;
			byt = byt | c;
			write (fd, &byt, 1);
			break;
		}
	}
	printf("Compressed file 'CFILE' has been successfully created.\n");
	system ("chmod 666 CFILE");
	close (fd);
	return 0;
}
