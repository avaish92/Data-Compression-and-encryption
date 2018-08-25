#include "prototype.h"

int encryption2 (char * a, char * ekey)
{
	unsigned char c, byt;
	int fd, i, n;
	fd = open ("CFILE", O_WRONLY | O_CREAT);
	if (fd < 0)
	{
		perror ("open");
		exit_application ();
	}

	i = 0;
	n = 0;
	while (1)
	{	
		c = c ^ c; 
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		c = c << 6;
		byt = byt ^ byt ;
		byt = byt | c;
		c = c ^ c;
		i++;
		if (a[i] == '\0')
		{
			c = 3;
			c = c << 6;
			c = c >> 2;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		}	
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		c = c << 6; 
		c = c >> 2;
		byt = byt | c;
		c = c ^ c;
		i++;
		if (a[i] == '\0')
		{
			c = 3;
			c = c << 6;
			c = c >> 4;
			byt = byt | c;
			c = c ^ c;
			write(fd, &byt, 1);
			byt = byt ^ byt; 
			break;
		}
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		c = c << 6;
		c = c >> 4;
		byt = byt | c;
		c = c ^ c;
		i++;
		if (a[i] == '\0')
		{
			c = 3;
			c = c << 6;
			c = c >> 6;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt ;
			break;
		}
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		c = c << 6;
		c = c >> 6;
		byt = byt | c;
		c = c ^ c;
		write (fd, &byt, 1);
		byt = byt ^ byt;
		i++;
		if (a[i] == '\0')
		{
			c = 3;
			c = c << 6;
			byt = byt | c;
			c =  c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
		}  
		
			
	}
	printf("The Cipher Text file 'CFILE' is successfully created.\n");
	system ("chmod 666 CFILE");
	close (fd);
	return 0;
}
