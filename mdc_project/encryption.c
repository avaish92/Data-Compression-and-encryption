#include "prototype.h"

int encryption_compress (void)
{
	char b[1000], *a, *ekey, n, cl;
	printf("\nEnter the filename you want to compress or encrypt :\t");
	scanf("%s", b);
	
	a = read_file (b);
	int i = 0;
	while(a[i] != '\0')
	{
		i++;
	}
	printf("File %s", b);
	printf("\n");
	printf("%s", a);
	printf("\n");
	n = i;
	printf("Number of charaters : %d\n\n", n);

	ekey = find_key (a, n);
	i = 0;
	while(ekey[i] != '\0')
	{
		++i;
	}
	printf("Cryptographic key\n");
	printf("%s", ekey);
	printf("\n");
	printf("Number of characters : %d\n", i);

	cl = code_length (i);
	
	printf("The Code length is %d bits.\n", cl);

	switch (cl)
	{
	case 0: printf("There is no data in the file.\n");
		break;
	case 1:	printf("Your data is protected.\tNo need of encryption.\t");
		break;
	case 2: encryption2 (a, ekey);
		break;
	case 3: encryption3 (a, ekey);
		break;
	case 4: encryption4 (a, ekey);
		break;
	case 5: encryption5 (a, ekey);
		break;
	case 6: encryption6 (a, ekey);
		break;
	case 7:	encryption7 (a, ekey);	
		break;
	default: printf("The file cannot be encrypted or compressed.\n");
		break;	 
	}
	return 0;
}
