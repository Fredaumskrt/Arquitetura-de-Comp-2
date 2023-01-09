# programa 17
# Escreva um programa que compute a série de Fibonacci, a série é definida como:
# 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...

# Ass:
# A[0] = $s0
# x = $s1
# y = $s2
# z = $s3

.text
.globl main
main:
addi $s0, $zero, 0x1001 # A[0] = 0x0000 1001
sll $s0, $s0, 16 # A[0] = 0x1001 0000

addi $t0, $zero, 100 # t0 = 100
addi $t1, $zero, 1 # t1 = 1
addi $t4, $zero, 4 # t4 = 4
add $t2, $zero, $s0 # t2 = END BASE

loop:
beq $t0, $zero, fim

lw $s1, 0($t2) # x = [i]
addi $t2, $t2, 4 # t2 += 4
lw $s2, 0($t2) # y = [i + 1]
addi $t2, $t2, 4 # t2 += 4

add $s3, $s1, $s2 # z = x + y
sw $s3, 0($t2) # A[i + 2] = z
sub $t2, $t2, $t4 # t2 -= 4

sub $t0, $t0, $t1 # t0--
j loop
fim:

.data
x: .word 1
y: .word 1
