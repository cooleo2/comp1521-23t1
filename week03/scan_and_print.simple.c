#include <stdio.h>

int main(void) {
    int i;
    int numbers[10] = {0};

main__scan_inital:
    i = 0;
main__scan_condition:
    if (i >= 10) goto main__scan_end;
main__scan_body:
    scanf("%d", &numbers[i]);
main__scan_increment:
    i++;
    goto main__scan_condition;
main__scan_end:


main__print_inital:
    i = 0;
main__print_condition:
    if (i >= 10) goto main__print_end;
main__print_body:
    printf("%d ", numbers[i]);
main__print_increment:
    i++;
    goto main__print_condition;
main__print_end:

}
