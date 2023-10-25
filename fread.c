#include <stdio.h>
#define ARRSIZE 8192

int main()
{
	FILE *readptr;
	char buff[ARRSIZE];
	char* entrfil = "/usr/lib/locale/locale-archive";

	readptr = fopen(entrfil, "r");
	fread(buff, sizeof(buff), 1, readptr);
	fclose(readptr);
	
	return 0;
}	
