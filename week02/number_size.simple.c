#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x >= 1000) goto small_big_print;
    if (x <= 100) goto small_big_print;

    medium_print:
        printf("medium\n");
        goto epilogue;

    small_big_print:
        printf("small/big\n");


    epilogue:
        return 0;
}
