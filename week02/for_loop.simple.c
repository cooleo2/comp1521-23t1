// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
    // i.e. it is a while loop with a counter built in.

    
main_i_init:
    int x = 24;
main_i_cond:
    if (x >= 42) goto main_i_false;
main_i_step:
    printf("%d\n", x);
    x += 3;
    goto main_i_cond;
main_i_false:
main__epi:

}