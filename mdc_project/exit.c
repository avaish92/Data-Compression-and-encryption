#include "prototype.h"

int exit_application (void)
{
	printf("Requesting all remaining modules to terminate....\n");
	printf("\n.");
	sleep(1);
	printf("\n..");
	sleep(1);
	printf("\n...\n");
	sleep(1);
	printf("Terminated\n");
	printf("\n\n\nCopyright (c) Aman Vaishya 2015\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
	exit (EXIT_SUCCESS);
	return 0;
}
