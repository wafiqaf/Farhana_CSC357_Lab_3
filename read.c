#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define ARRSIZE 1

int main()
{
	int file;
	char* stack = (char*) calloc(ARRSIZE, sizeof(char));
	char* entrfil = "/usr/lib/locale/locale-archive";

	file = open(entrfil, O_RDONLY);
	if (file < 0) {
		perror("Could not open file.");
		exit(1);
	}
	
	read(file, stack, ARRSIZE);
	// safety procedures
	close(file);
	free(stack);
	stack = NULL;
	free(entrfil);
	stack = NULL;
}	
