#include "prototype.h"

int find_index (char a, char * ekey)
{
	int  i = 0;
	while(ekey[i] != '\0')
	{
		if(a == ekey[i])
		{
			return i;		
		}
		i++;
	}
	printf("INVALID Encryption key.\n");
	exit_application ();
}
