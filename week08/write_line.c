// Write a C program, write_line.c, which is given one command-line argument,
// the name of a file, and which reads a line from stdin, and writes it to the
// specified file; if the file exists, it should be overwritten (rather than appended).
//


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
    }

    FILE *fp = fopen(argv[1], "a");

    if (fp == NULL) {
        perror(argv[1]);
        return 1;
    }

    int c;
    // Loop through every character in the terminal
    while ((c = fgetc(stdin)) != EOF && c != '\n') {
        // Write the character to the file
        fputc(c, fp);
    }
    

    fclose(fp);

    return 0;
}

// What change would we make if we wanted to append to a file rather than
// overwrite it?
