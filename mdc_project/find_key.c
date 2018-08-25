#include "prototype.h"

char * find_key (char * a, int n)
{
	char * key;
	key = NULL;
	int i , flag, j, k, fd;
	
	fd = open ("CKEY", O_WRONLY | O_CREAT);
	if (fd < 0)
	{
		perror ("open");
		exit_application ();
	}
	i = 0;
	flag = 0;
	k = 0;
	while(a[i] != '\0')
	{
		for (j=0; j<i; j++)
		{
			if (a[i] == a[j])
			{				
				flag = 1;
				break;
			}
			else
			{
				flag = 0;
			}
		}
		if (flag == 0)
		{
			key = realloc(key, k+1);
			if(key == NULL)
			{
				perror ("realloc");
				exit_application ();
			}
			key[k] = a[i];
			k++;
		}
		i++;
	} 
	key[k] = '\0';
	k = 0;
	while(key[k] != '\0')
	{
		k++;
	}
	write (fd, key, k);
	printf ("Master file created in the file named CKEY.\n");
	system ("chmod 666 CKEY");
	close (fd);
	return key;
}
