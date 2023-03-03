N_ELEMENTS = 5

main:
	# $t0 = i
	# $t1 = address of array

main__for_init:
    li 	$t0, 0		# int i = 0;
    
main__for_cond:
	bge $t0, N_ELEMENTS, main__for_end # if (i >= N_ELEMENTS) goto main__for_end;

main__for_body:
	la  $t1, array	# Address of the start of the array
	mult $t2, $t0, 1  # Calculating the offset
	add $t1, $t1, $t2 # Calculate &array[i]
	lb 	$t3, ($t1) # Get the value at address $t1


	li	$v0, 11			# syscall 11: print_char
	move $a0, $t3
	syscall				# putchar(*(array + i));

	li	$v0, 11			# syscall 11: print_char
	li	$a0, '\n'		#
	syscall				# putchar('\n');

main__for_incr:
    addi $t0, $t0, 1
    j main__for_cond
main__for_end:


	li	$v0, 0
	jr	$ra			# return 0;

	.data

array:
	.byte	'h', 'e', 'l', 'l', 'o'
