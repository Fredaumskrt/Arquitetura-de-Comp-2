# programa 16
# y = x^3 + 1 se x > 0
# y = x^4 - 1 se x <= 0 

# Ass:
# A[0] = $s0
# x = $s1
# y = $s2 

.text
.globl main
main:
addi $s0, $zero, 0x1001 # A[0] = 0x0000 1001
sll $s0, $s0, 16 # A[0] = 0x1001 0000

lw $s1, 0($s0) # x = A[0]

addi $t7, $zero, 1 # t7 = 1
slt $t0, $zero, $s1 #if(0 < x) t0 = 1
bne $t0, $zero, true # if(t0 != 0) -> true

addi $t1, $zero, 4 # t1 = 4
addi $t2, $zero, 1 # t2 = 1
loop1:
mult $s1, $t2 # x * t2
mflo $t2 # t2 = resultado
sub $t1, $t1, $t7 # t1--
bne $t1, $zero, loop1 # if(t1 != 0) -> loop 

addi $t6, $zero, 1 # t6 = 1
sub $s2, $t2, $t6 # y = x^4 - 1
sw $s2, 4($s0) # A[1] = y

j fim

true: 

addi $t3, $zero, 3 # t3 = 3
addi $t4, $zero, 1 # t4 = 1
loop2:
mult $s1, $t4 # x * t4
mflo $t4 # t4 = resultado
sub $t3, $t3, $t7 # t3--
bne $t3, $zero, loop2 # if(t3 != 0) -> loop 

addi $s2, $t4, 1 # y = x^3 + 1
sw $s2, 4($s0) # A[1] = y

fim:

.data
x: .word -2
