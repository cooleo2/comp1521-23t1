/**
 * Write a C program, print_diary.c,
 * which prints the contents of the file $HOME/diary to stdout.
 * 
 * Be sure to handle any errors!
 * snprintf is a convenient function for constructing the pathname of the diary file.
 * (it's also pretty handy for subset3 of a certain assignment.)
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIARY_PATH "/diary"


int main(void) {
    // Get $HOME
    char *home_dir = getenv("HOME");

    int size_of_string = strlen(home_dir) + strlen("/diary") + 1;
    char *full_path = malloc(sizeof(char) * size_of_string);

    snprintf(full_path, size_of_string, "%s/diary", home_dir);
    printf("%s\n",full_path );


    // TODO: construct full_path in order to open the file 
    FILE *stream = fopen(full_path, "r");
    if (stream == NULL) {
        perror(full_path);
        exit(1);
    }

    int c;
    while ((c = fgetc(stream)) != EOF) {
        putchar(c);
    }

    fclose(stream);

    
    free(full_path);
    return 0;
}
