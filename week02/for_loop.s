main:
    # $t0 = x
    
main_i_init:
    li  $t0,  24   # int x = 24;
main_i_cond:
    bge $t0,  42, main_i_false #if (x >= 42) goto main_i_false;
main_i_step:
    
    move    $a0, $t0  #printf("%d\n", x);
    li      $v0, 1
    syscall

    li      $a0, '\n'  
    li      $v0, 11
    syscall

    addi    $t0, $t0, 3 #x += 3;

    j   main_i_cond
main_i_false:
main__epi:


    li      $v0, 0
    jr      $ra

.data
