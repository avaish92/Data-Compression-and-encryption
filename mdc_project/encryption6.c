#include "prototype.h"

int encryption6 (char * a, char * ekey)
{
	unsigned char c, byt, d;
	int fd, i , n;
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
		d = d ^ d;
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		c = c << 2;
		byt = byt ^ byt;
		byt = byt | c;
		c = c ^ c;
		i++;
		if (a[i] == '\0')
		{
			d = c = 63;
			c = c << 2;
			c = c >> 6;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			c = d;
			d = d ^ d;
			c = c << 4;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		}

		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		d = c;
		c = c << 2;
		c = c >> 6;
		byt = byt | c;
		c = c ^ c;
		write (fd, &byt, 1);
		byt = byt ^ byt;
		d = d << 4;
		byt = byt | d;
		d = d ^ d;
		i++;
		
		if (a[i] == '\0')
		{
			d = c = 63;
			c = c << 2;
			c = c >> 4;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			d = d << 6;
			byt = byt | d;
			d = d ^ d;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		}

		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		d = c;
		c = c << 2;
		c = c >> 4;
		byt = byt | c;
		c = c ^ c;
		write (fd, &byt, 1);
		byt = byt ^ byt;
		d = d << 6;
		byt = byt | d;
		d = d ^ d;
		i++;
		
		if (a[i] == '\0')
		{
			c = 63;
			c = c << 2;
			c = c >> 2;
			byt = byt | c;
			c = c ^ c ;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		} 
		
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		c = c << 2;
		c = c >> 2;
		byt = byt | c;
		c = c ^ c;
		write (fd, &byt, 1);
		byt = byt ^ byt;
		i++;
		
		if (a[i] == '\0')
		{
			c = 63;
			c = c << 2;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		}
	}
	printf("The Cypher Text has been written in the file 'CFILE.'\n");
	system ("chmod 666 CFILE");
	close (fd);
	return 0;
}
