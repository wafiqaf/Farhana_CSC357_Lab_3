#include <stdio.h>
#define ARRSIZE 8192

int main()
{
	FILE *readptr;
	char buff[ARRSIZE];

	readptr = fopen("sample.txt", "r");
	fread(buff, sizeof(buff), 1, readptr);
	fclose(readptr);
	
	return 0;
}	
