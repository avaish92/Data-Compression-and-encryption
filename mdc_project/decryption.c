#include "prototype.h"

int decryption_decompress (void)
{
	char b[1000], e[1000];
	printf("Enter the filename of the file to be decrypted\t");
	scanf ("%s", b);
	printf("Enter the filename of master file key:\t");
	scanf ("%s", e);
	
	char * ekey, * data; 
	data = read_file (b);
	ekey = read_file (e);
	int i = 0, cl;
	while (ekey[i] != '\0')
	{
		i++;
	}
	i = i - 1;
	printf("Number of characters in the file is %d.\n", i);
	cl = code_length (i);
	printf("Code length is %dbits\n", cl);
	switch(cl)
	{
	case 0: printf("The file cannot be decrypted.\nAs the master array is INVALID\n");
		exit_application ();
	case 1: printf("The file cannot be decrypted.\nAs the master array is INVALID\n\n");
		exit_application ();
		break;
	case 2: decryption2 (data, ekey);
		break;
	case 3: decryption3 (data, ekey); 
		break;
	case 4: decryption4 (data, ekey);
		break;
	case 5:	decryption5 (data, ekey);
		break;
	case 6: decryption6 (data, ekey);
		break;
	case 7: decryption7 (data, ekey);
		break;
	default: printf("Unable to decrypt file\n");
		 break; 
	}
	return 0;
}
