// Write a C program, chmod_if_public_write.c, which is given 1+ command-line
// arguments which are the pathnames of files or directories.

// If the file or directory is publically-writeable, it should change it to be
// not publically-writeable, leaving other permissions unchanged.

// It also should print a line to stdout as per the example below.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_needed(char *pathname);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_needed(argv[arg]);
    }
    return 0;
}

void chmod_if_needed(char *pathname) {
    // TODO: Implement this function.
    struct stat s;
    if (stat(pathname, &s) != 0) {
        perror("stat");
        exit(1);
    }

    mode_t new_mode;

    // Check whether our file is public writable
    if (s.st_mode & S_IXGRP) {
        printf("Group Executable\n");
        // Make it not group executable

        // EXAMPLE, only considering last 9 permission bits.
        // SI_IWOTH = 0b000000010
        // mode =     0b010101010 (This is currently publicly writeable)
        // ~SI_IWOTH= 0b111111101
        // anded mode=0b010101000
        new_mode = s.st_mode & ~S_IXGRP;

        if (chmod(pathname, new_mode) != 0) {
            perror(pathname);
            exit(1);
        }

    } else {
        printf("Not Group Executable\n");
    }
}
