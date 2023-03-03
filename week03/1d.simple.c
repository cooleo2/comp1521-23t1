#include <stdio.h>
#define N_ELEMENTS 5

int main(void) {
    char array[N_ELEMENTS] = {'h', 'e', 'l', 'l', 'o'};

main__for_init:
    int i = 0;
    
main__for_cond:
    if (i >= N_ELEMENTS) goto main__for_end;
main__for_body:
    putchar(*(array + i));
    putchar('\n');

main__for_incr:
    i++;
    goto main__for_cond;
main__for_end:


    return 0;
}


// What if we had
// int array[N_ELEMENTS] = {3, 1, 4, 1, 5};

