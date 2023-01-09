# programa 18
# Escreva um programa que leia um número armazenado na primeira posição livre da memória. Após a
# leitura desse número, um registrador qualquer será um flag, isto é, se esse número lido estiver na faixa de
# 50 a 100 ou 150 a 200 esse registrador deverá conter um “1”, caso contrário esse registrador deverá conter
# “0”.

# Ass:
# A[0] = $s0
# x = $s1
# FLAG = $s2

.text
.globl main
main:
addi $s0, $zero, 0x1001 # A[0] = 0x0000 1001
sll $s0, $s0, 16 # A[0] = 0x1001 0000

lw $s1, 0($s0) # x = A[0]

addi $t0, $zero, 50 # t0 = 50
addi $t1, $zero, 100 # t1 = 100
addi $t2, $zero, 150 # t2 = 150
addi $t3, $zero, 200 # t3 = 200
addi $t4, $zero, 1 # t4 = 1

slt $s2, $t0, $s1 # if (50 < X) FLAG = 1
beq $s2, $zero, fim1 # if(false) -> fim
slt $s2, $s1, $t1 # if (X < 100) FLAG = 1
beq $s2, $zero, fim1 # if(false) -> fim

beq $s2, $t4, fim2 # OR

fim1:
slt $s2, $t2, $s1 # if (150 < X) FLAG = 1
beq $s2, $zero, fim2 # if(false) -> fim
slt $s2, $s1, $t3 #if (X < 200) FLAG = 1

fim2:

.data
X: .word 162
