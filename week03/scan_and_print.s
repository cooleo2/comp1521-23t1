main:
        # $t0 = i

main__scan_inital:
        li      $t0, 0  # int i = 0
main__scan_condition:
        bge     $t0, 10, main__scan_end
main__scan_body:
        # scanf("%d", &numbers[i]);
        la      $t1, numbers # Address of the start of the array
        mul    $t2, $t0, 4  # Calculating the offset (i * 4)
        add     $t1, $t1, $t2 # Calculate &numbers[i]
        
        li      $v0, 5
        syscall                 # Scanned in int into $v0
        sw      $v0, ($t1)      # Storing the int into address $t1

main__scan_increment:
        addi  $t0, 1
        j main__scan_condition
main__scan_end:

        
main__print_inital:
        li      $t0, 0  # int i = 0
main__print_condition:
        bge     $t0, 10, main__print_end
main__print_body:
        
        mul    $t3, $t0, 4  # Calculating the offset (i * 4)
        lw      $a0, numbers($t3) # Load the number we want to print into $a0
        li      $v0, 1
        syscall

main__print_increment:
        addi  $t0, 1
        j main__print_condition
main__print_end:



        

        .data
numbers:
        .word 0:10
