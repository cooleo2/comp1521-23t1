// Write a C program, first_line.c, which is given one command-line argument -
// the name of a file - and which prints the first line of that file to stdout.
// If given an incorrect number of arguments, or if there was an error opening
// the file, it should print a suitable error message.
//
// A line may be of any size.

#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 65536

int main(int argc, char *argv[]) {

    // Eg. ./first_line file_to_read.txt
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror(argv[1]);
        return 1;
    }
    char first_line[MAX_LINE];

    fgets(first_line, MAX_LINE, fp);
    printf("%s\n", first_line);

    fclose(fp);

    return 0;
}
