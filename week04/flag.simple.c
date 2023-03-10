#include <stdio.h>
#define N_ROWS 6
#define N_COLS 12


char flag[N_ROWS][N_COLS] = {
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'}
};

int main(void) {

main__for_row_init:
    int row = 0;
main__for_row_cond:
    if (row >= 6) goto main__for_row_end;
main__for_row_body:

main__for_col_init:
    int col = 0;
main__for_col_cond:
    if (col >= 12) goto main__for_col_end;
main__for_col_body:

    printf("%c", flag[row][col]); // TODO: Calculate flag[row][col] 
    //flag + (row * 12 + col) * 1)

main__for_col_step:
    col++;
main__for_col_end:

    printf("\n");

main__for_row_step:
    row++;
main__for_row_end:
}
