main:

main__prologue:
	begin
	push	$ra

main__body:
	li	$s0, 70

	li	$a0, 4
	li	$a1, 5
	jal	add

	# $s0 = 70

main__epilogue:
	pop	$ra
	end

	li	$v0, 0
	jr	$ra				# return 0;


	
########################################################################
# .TEXT <add>
	.text
add:

	# Args: 
	# - $a0 - int: First number to add
	# - $a1 - int: Second number to add
	# Returns: 
	# - int - result
	#
	# Frame:	[$ra, $s0]
	# Uses: 	[$v0, $a0, $a1, $s0]
	# Clobbers:	[$v0, $a0, $a1]
	#
	# Locals:
	#   - $s0: int result
	#
	# Structure:
	#   - add
	#     -> [prologue]
	#     -> [body]
	#     -> [epilogue]

add__prologue:
	begin
	push	$ra
	push	$s0

add__body:
	add	$s0, $a0, $a1			# result = num1 + num2

	li	$v0, 1				# syscall 1: print_int
	move	$a0, $s0			# 
	syscall					# printf("%d", value);

	li	$v0, 11				# syscall 11: print_char
	li	$a0, '\n'			#
	syscall					# putchar('\n');


	move	$v0, $s0

add__epilogue:
	pop	$s0
	pop	$ra
	end

	jr	$ra				# return 0;
