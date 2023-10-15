#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validate_args(int argc, char *argv[]) {

	if (argc < 2) {
		fprintf(stdout, "usage: %s input\n", argv[0]);
		exit(-1);
	}
}

FILE *open_file(char *name, char *mode) {

	FILE *file = fopen(name, mode);
	if (file == NULL) {
		perror(name);
		exit(-1);
	}
	return file;
}

void linegetter(FILE *in_file) {
	char *line = NULL;
	char *lastline = NULL;
	size_t size;

	while (getline(&line, &size, in_file) > 0) {
		// print current line
		printf("%s", line);
		
		// if it is not the end of the program, 
		printf("%s", &line[(strlen(line))]);
		//char lastchar = &line[(strlen(line)-1)];
		//printf("%d", lastchar);

		if (&line[(strlen(line)-2)] == '\n') {
			// save current line as last line
			printf("hi");
			lastline = strdup(line);
		} else {
			printf("hello");
			printf("%s", lastline);
			printf("%s", line);
		}
	}

	//printf("%s", lastline);
	//printf("%s", line);
	
	free(lastline);
	free(line);
}

int main(int argc, char *argv[]) {

	FILE *in;
	validate_args(argc, argv);
	in = open_file(argv[1], "r");
	linegetter(in);
	fclose(in);
	return 0;
}
