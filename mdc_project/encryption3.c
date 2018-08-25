#include "prototype.h"

int encryption3 (char * a, char * ekey)
{
	unsigned char byt, c, d;
	int n, i, fd;

	fd = open ("CFILE", O_WRONLY | O_CREAT);
	if(fd < 0)
	{
		perror ("open");
		exit_application ();
	}
	i = 0;
	n = 0;
	while (1)
	{
		byt = byt ^ byt;
		c = c ^ c;
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		n = 0;
		c = c << 5;
		byt = byt | c;
		c = c ^ c;
		i++;
		if (a[i] == '\0')
		{
			c = 7;
			c = c << 5;
			c = c >> 3;
			byt = byt | c;
			c = c ^ c ;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		}
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		n = 0;
		c = c << 5;
		c = c >> 3;
		byt = byt | c;
		c = c ^ c;
		i++;
		if (a[i] == '\0')
		{
			d = c = 7;
			c = c << 5;
			c = c >> 6;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			d = d << 7;
			byt = byt | d;
			d = d ^ d;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		} 
		
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		n = 0;
		d = c;
		c = c << 5;
		c = c >> 6;
		byt = byt | c;
		c = c ^ c;
		write (fd, &byt, 1);
		byt = byt ^ byt;
		d = d << 7;
		byt = byt | d;
		d = d ^ d;
		i++;
		
		if (a[i] == '\0')
		{
			c = 7;
			c = c << 5;
			c = c >> 1;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		} 
		
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		n = 0;
		c = c << 5;	
		c = c >> 1;
		byt = byt | c;
		c = c ^ c;
		i++;
		
		if (a[i] == '\0')
		{
			c = 7;
			c = c << 5;
			c = c >> 4;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break; 
		}

		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		n = 0;
		c = c << 5;
		c = c >> 4;
		byt = byt | c;
		c = c ^ c;
		i++;
		
		if (a[i] == '\0')
		{
			c = d = 7;
			c = c << 5;
			c = c >> 7;
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
		n = 0;
		d = c;
		c = c << 5;	
		c = c >> 7;
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
			c = 7;
			c = c << 5;
			c = c >> 2;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		}

		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		n = 0;
		c = c << 5;
		c = c >> 2;
		byt = byt | c;
		c = c ^ c;
		i++;
		
		if (a[i] == '\0')
		{
			c = 7;
			c = c << 5;
			c = c >> 5;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		}

		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		n = 0;
		c = c << 5;
		c = c >> 5;
		byt = byt | c;
		c = c ^ c;
		write (fd, &byt, 1);
		byt = byt ^ byt;
		
		i++;
		if (a[i] == '\0')
		{
			c = 7;
			c = c << 5;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		}
	}
	printf("Compressed file 'CFILE' has been successfully created.\n");
	system ("chmod 666 CFILE");
	close (fd);
	return 0;
}
