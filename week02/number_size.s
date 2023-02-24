main:
    # $t0 = x

    la      $a0, prompt_str     # printf("Enter a number: ");
    li      $v0, 4
    syscall

    li      $v0, 5          # scanf("%d", x);
    syscall
    move    $t0, $v0

    bge $t0, 1000, small_big_print    # if (x >= 1000) goto small_big_print;
    ble $t0, 100, small_big_print   # if (x <= 100) goto small_big_print;

medium_print:
    la      $a0, medium_str     # printf("Enter a number: ");
    li      $v0, 4
    syscall
    j       epilogue
 
small_big_print:
    la      $a0, small_big_str     # printf("Enter a number: ");
    li      $v0, 4
    syscall

epilogue:
    li      $v0, 0
    jr      $ra

.data
prompt_str:
    .asciiz "Enter a number: "
medium_str:
    .asciiz "medium\n"
small_big_str:
    .asciiz "small/big\n"