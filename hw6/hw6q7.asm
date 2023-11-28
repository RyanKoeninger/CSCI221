main:

li $a0, 3

numberOfBitsNotSet:

addi $sp, $sp, -4
sw $ra, ($sp)
li $t0, 0 # num zeroes
li $t1, 0 # counter
li $t3, 32 # value compared to

loop:
beq $t3, $t1, endloop # end when reach 32 bits
move $t2, $a0 # store a0, which is set in main
srl $a0, $a0, 1 # left shift
srr $a0, $a0, 1 # right shift
bne $a0, $t2, skip
addi $t0, $t0, 1

skip: 
addi $t1, $t1, 1
srl $a0, $a0, 1
j loop

endloop: 
move $v0, $t0 # result in v0
lw $ra, ($sp)
addi $sp, $sp, 4
jr $ra