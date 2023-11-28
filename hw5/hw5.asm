main:


li $a0, 3 # number of times iterating / the desired power of 2

li $s0, 1 # iterator
li $s1, 2 # number multiplied

loop:
beq $a0, $s0, end # branch if these are equal

mul $s1, $s1, 2 # multiplies by 2

addi $s0, $s0, 1 # adds 1 to iterator

j loop # return to top

end: 

move $v1, $s1 # place value in v1

li $v0, 10
syscall
