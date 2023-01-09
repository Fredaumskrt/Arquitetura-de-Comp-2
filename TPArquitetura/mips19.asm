# programa 19
# Escreva um programa que calcule a mediana de 3 números armazenados na memória. Após encontrar
# essa mediana, escrevê-la na posição seguinte aos 3 números.

# Ass:
# A[0] = $s0
# A = $s1
# B = $s2
# C = $s3
# MED = $s4

.text
.globl main
main:
addi $s0, $zero, 0x1001 # A[0] = 0x0000 1001
sll $s0, $s0, 16 # A[0] = 0x1001 0000

lw $s1, 0($s0) # A = A[0]
lw $s2, 4($s0) # B = A[1]
lw $s3, 8($s0) # C = A[2]

MEDA:
slt $t0, $s1, $s2 # if(A < B) t0 = 1
slt $t1, $s1, $s3 # if(A < C) t0 = 1

beq $t0, $t1, MEDB # if(t0 == t1) -> MEDB
add $s4, $zero, $s1 # A é a mediana
j fim

MEDB:
slt $t0, $s2, $s1 # if(B < A) t0 = 1
slt $t1, $s2, $s3 # if(B < C) t0 = 1

beq $t0, $t1, MEDC # if(t0 == t1) -> MEDC
add $s4, $zero, $s2 # B é a mediana
j fim

MEDC:
slt $t0, $s3, $s1 # if(C < A) t0 = 1
slt $t1, $s3, $s2 # if(C < B) t0 = 1

beq $t0, $t1, fim # if(t0 == t1) -> fim
add $s4, $zero, $s3 # C é a mediana
j fim

fim:
sw $s4, 12($s0) # A[3] = MED

.data
A: .word 23
B: .word 98
C: .word 17
