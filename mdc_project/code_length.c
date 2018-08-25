#include "prototype.h"

int code_length (int n)
{
	if(n == 0) return 0;		
	if(n < 2) return 1;
	if(n < 4) return 2;
	if(n < 8) return 3;
	if(n < 16) return 4;
	if(n < 32) return 5;
	if(n < 64) return 6;
	if(n < 128) return 7;
}
