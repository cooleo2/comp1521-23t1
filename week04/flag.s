main:
	# $t0 = row
	# $t1 = col
	# $t2 = flag

main__for_row_init:
    	li	$t0, 0
main__for_row_cond:
	bge	$t0, 6, main__for_row_end
main__for_row_body:

main__for_col_init:
    	li	$t1, 0
main__for_col_cond:
	bge	$t1, 12, main__for_col_end
main__for_col_body:
	la	$t2, flag
	mul	$t3, $t0, 12	# row * 12 (which is the size of a row)
	add	$t3, $t3, $t1	# col + (row*12) and store it back into $t3
	mul	$t3, $t3, 1	# size of a char

	add	$t4, $t3, $t2	# address of our element

	lb	$a0, ($t4)

	li	$v0, 11			# syscall 11: print_char
	syscall				# putchar(*(array + i));

    #printf("%c", flag[row][col]); // TODO: Calculate flag[row][col] 
    #//flag + (row * 12 + col) * 1)

main__for_col_step:
    	addi	$t1, $t1, 1
	j	main__for_col_cond
main__for_col_end:

	li	$v0, 11			# syscall 11: print_char
	li	$a0, '\n'		#
	syscall				# putchar('\n');

main__for_row_step:
    	addi	$t0, $t0, 1
	j	main__for_row_cond
main__for_row_end:
 
 	li	$v0, 0
	jr	$ra			# return 0;
 
        .data
flag:

        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
