.data 

xs: .word 2, 4, 6
ys: .word 0, 1, 2

.text

main:

la $a0, xs  #address of xs
la $a2, ys  #address of ys

li $a1, 3   #length of xs
li $a3, 3   #length of ys

li $t0, 0   #iterator
li $t1, 4   #4 used to get addresses


loop:
beq $t0, $a3, end #if iterator gets to 3, break loop

lw $t3, ($a2) #load 1st element in ys to t3

addi $a2, $a2, 4 #add 4 to a2 so now it points to the second element in ys

mul $t3, $t3, $t1 #multiply t3 by 4 so it can be used to move between elements

add $t4, $a0, $t3 #now at element in xs

lw $t5, ($t4) #element stored as t5

addi $t5, $t5, 1# add by 1

sw $t5, ($t4)# replace old element with iterated version

addi $t0, $t0, 1 #iterator up by 1

j loop

end:


li $v0, 10
syscall

