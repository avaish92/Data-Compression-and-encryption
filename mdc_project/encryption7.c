#include "prototype.h"

int encryption7 (char * a, char * ekey)
{
	unsigned char c, d, byt;
	int fd, i, n = 0;
	fd = open ("CFILE", O_WRONLY | O_CREAT);
	if (fd < 0)
	{
		perror ("open");
		exit_application ();
	}
	i = 0;
	while (1)
	{
		n = find_index (a[i], ekey);
		c = c ^ c;
		c = (unsigned char)n;
		n = 0;
		byt = byt ^ byt;
		c = c << 1;
		byt = byt | c;
		c = c ^ c;
		i++;
		if (a[i] == '\0')
		{
			c = 127;
			d = c;
			c = c << 1;
			c = c >> 7;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			d = d << 2;
			byt = byt | d;
			d = d ^ d;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;			
		}
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		d = c;
		n = 0;
		c = c << 1;
		c = c >> 7;
		byt = byt | c;
		c = c ^ c;
		write (fd, &byt, 1);
		byt = byt ^ byt;
		d = d << 2;
		byt = byt | d;
		d = d ^ d; 
		i++;
		if (a[i] == '\0')
		{
			c = 127;
			d = c;
			c = c << 1;
			c = c >> 6;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			d = d << 3;
			byt = byt | d;
			d = d ^ d; 
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;  
		}
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		d = c;
		n = 0;
		c = c << 1;
		c = c >> 6;
		byt = byt | c;
		c = c ^ c;
		write (fd, &byt, 1);
		byt = byt ^ byt;
		d = d << 3;
		byt = byt | d;
		d = d ^ d;
		i++;
		if (a[i] == '\0' )
		{
			c = 127;
			d = c;
			c = c << 1;
			c = c >> 5;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			d = d << 4;
			byt = byt | d;
			d = d ^ d;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		}
		n = find_index (a[i], ekey);
		c = (unsigned int)n;
		d = c;
		n = 0;
		c = c << 1;
		c = c >> 5;
		byt = byt | c;
		c = c ^ c;
		write (fd, &byt, 1);
		byt = byt ^ byt;
		d = d << 4;
		byt = byt | d;
		d = d ^ d;
		i++;
		if (a[i] == '\0' )
		{
			c = 127;
			d = c;
			c = c << 1;
			c = c >> 4;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1 );
			byt = byt ^ byt;
			d = d << 5;
			byt = byt | d;
			d = d ^ d;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break; 
		}	 
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		d = c;
		n = 0;
		c = c << 1;
		c = c >> 4;
		byt = byt | c;
		c = c ^ c;
		write (fd, &byt, 1);
		byt = byt ^ byt;
		d = d << 5;
		byt = byt | d;
		d = d ^ d;
		i++;
		if (a[i] == '\0' )
		{
			c = 127;
			d = c;
			c = c << 1;
			c = c >> 3;
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
		n = 0;
		c = c << 1;
		c = c >> 3;
		byt = byt | c;
		c = c ^ c;
		write (fd, &byt, 1);
		byt = byt ^ byt;
		d = d << 6;
		byt = byt | d;
		d = d ^ d;
		i++;
		if ( a[i] == '\0' )
		{
			c = 127;
			d = c;
			c = c << 1;
			c = c >> 2;
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
		d = c;
		n = 0;
		c = c << 1;
		c = c >> 2;
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
			c = 127;
			c = c << 1;
			c = c >> 1;
			byt = byt | c;
			c = c ^ c;
			write (fd, &byt, 1);
			byt = byt ^ byt;
			break;
		}
		n = find_index (a[i], ekey);
		c = (unsigned char)n;
		c = c << 1;
		c = c >> 1;
		byt = byt | c;
		c = c ^ c;
		write (fd, &byt, 1);
		byt = byt ^ byt;
		i++;
		if (a[i] == '\0')
		{
			c = 127;
			c = c << 1;
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
