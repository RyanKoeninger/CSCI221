main:

addi $sp, $sp, -4  # allocate space for z 
li $t0, 2 # load 2 into t0
sw $t0, ($sp) # put 2 back in stack: this is z

addi $sp, $sp, -4
lw $t1, 4($sp)
sw $t1, $sp
move $v0, $zero

addi $v0, $v0, 1
sw $v0, ($sp)
sw $t1, $sp
jal f


f: 
addi $sp, $sp, -4
sw $ra, ($sp) # store pointer to jump back later
addi($sp, $sp, -4) # space for i
li $t0, 5
sw $t0, ($sp) # i is in stack now

addi $sp, $sp, -4
lw $t1, 12($sp) # grab x to call g(x)
sw $t1, $sp # x in current stack

jal g # call g

add $v0, $t0, $v0
lw $ra, 8($sp)
addi $sp, $sp, 12
jr $ra

g: 
addi $sp, $sp, -4
sw $ra, ($sp)
addi $sp, $sp, -4
li $t0, 3
sw $t0,3 
lw $t1, 8($sp)
add $t0, $t0, $t1
move $v0, $t0

lw $ra, 4($sp)
addi $sp, $sp, 8
jr $ra