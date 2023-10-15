#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define ARRSIZE 2

int main()
{
	int file;
	char* stack = (char*) calloc(ARRSIZE, sizeof(char));

	file = open("sample.txt", O_RDONLY);
	if (file < 0) {
		perror("Could not open file.");
		exit(1);
	}
	
	read(file, stack, ARRSIZE);
	// safety procedures
	close(file);
	free(stack);
	stack = NULL;
}	
