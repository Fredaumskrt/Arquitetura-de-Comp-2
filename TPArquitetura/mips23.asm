# programa 23
# Seu programa deverá conter uma função que receba esses dois números e retorne o primeiro elevado ao segundo. 

# Ass:
# A[0] = $s0
# a = $s1
# b = $s2
# pow = $s3

.text
.globl main
main:
addi $s0, $zero, 0x1001 # A{0] = 0x0000 1001
sll $s0, $s0, 16 # A{0] = 0x1001 0000

lw $s1, 0($s0) # a = A[1]
lw $s2, 4($s0) # b = A[2]

add $a0, $zero, $s1 # a0 = a
add $a1, $zero, $s2 # a1 = b
jal func
add $s3, $zero, $v0 # pow = func(a, b)
sw $s3, 8($s0)
j fim

func:
addi $v0, $zero, 1 # v0 = 1
loop:
mult $v0, $a0 # v0 * a0
mflo $v0 # v0 = resultado
addi $a1, $a1, -1 # a1--
bne $a1, $zero, loop # while(a1 != 0) -> loop
jr $ra

fim:

.data
a: .word 5
b: .word 4
