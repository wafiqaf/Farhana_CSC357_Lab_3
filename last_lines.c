#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validate_args(int argc, char *argv[]) {

	if (argc < 2) {
		fprintf(stdout, "Please enter file!\n");
		exit(-1);
	} else if (argc > 2) {
		fprintf(stdout, "Too many files!\n");
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
	char *currline = NULL;
	
	int first = 0;
	size_t size;

	while (getline(&line, &size, in_file) > 0) {
		// if it's the first line, make that line the last line
		if (first == 0) {
			lastline = strdup(line);
			first++;
		// if it's the second line, make the current line line the line read
		} else if (first == 1) {
			currline = strdup(line);	
			first++;
		// in other cases, make the lastline the currline, etc
		} else {
			lastline = strdup(currline);
			currline = strdup(line);
		}
	}

	// edge cases + final printout
	// empty file
	if (lastline == NULL) {
		// print nothing :3
	} else if (first == 1) {
		printf("%s", line);
	} else {
		// print both the lastline and the line
		printf("%s", lastline);
		printf("%s", line);
	}

	// safety
	free(currline);	
	free(lastline);
	free(line);
	currline = NULL;
	lastline = NULL;
	line = NULL;
}

int main(int argc, char *argv[]) {

	FILE *in;
	validate_args(argc, argv);
	in = open_file(argv[1], "r");
	linegetter(in);
	fclose(in);
	return 0;
}
