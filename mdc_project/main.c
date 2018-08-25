#include "prototype.h"

int main()
{
	int choice;
	char ans[10];
	system ("clear");
	while(1)
	{
		printf("\n\n\n\nThis program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.");
		printf("\n\nBECAUSE THE PROGRAM IS LICENSED FREE OF CHARGE,THERE IS NO WARRANTY FOR THE PROGRAM,TO THE EXTENT PERMITTED BY APPLICABLE LAW.EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM ``AS IS'' WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED,INCLUDING,BUT NOT LIMITED TO,THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.THE ENTIRE RISK AS TO THE QUALITY AND PER‐FORMANCE OF THE PROGRAM IS WITH YOU.SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.");
		printf("\n\n\n\nCopyright © 2016 Aman Vaishya");
printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("Enter the Operation to be performed:\n");
choice:		printf("1. Compression\n");
		printf("2. Decompression\n");
		printf("0. Save and quit\n");
printf("\n\n");
		printf("Enter the operation to be performed ... !!");
		scanf("%d", &choice);
		
printf("\n\n");

		switch (choice)	
		{
			case 1: encryption_compress();
				break;
			case 2: decryption_decompress();
				break;
			case 0: exit_application ();
			default: printf("INVALID Option\n");
				 goto choice;
		} 
	}
	return 0;
}
