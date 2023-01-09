# programa 13
# Escreva um programa que leia da memória um valor de Temperatura TEMP. Se TEMP>=30 e TEMP
# <=50 uma variável FLAG, também na memória, deverá receber o valor 1, caso contrário, FLAG deverá
# ser zero.

# Ass:
# A[0] = $s0
# TEMP = $s1
# FLAG = $s2

.text
.globl main
main:
addi $s0, $zero, 0x1001 # A[0] = 0x0000 1001
sll $s0, $s0, 16 # A[0] = 0x1001 0000

addi $t0, $zero, 30 # t0 = 30
addi $t1, $zero, 50 # t1 = 50

lw $s1, 0($s0) # TEMP = A[0]
slt $t2, $s1, $t0 # if(30 < FLAG) t2 = 1 
bne $t2, $zero, fim # if(t2 != 0) -> fim
slt $t2, $t1, $s1 # if(TEMP > 50) t2 = 1 
bne $t2, $zero, fim # if(t2 != 0) ->  fim
addi $s2, $zero, 1 # FLAG = 1 
sw $s2, 4($s0) # A[1*4] = FLAG
fim:

.data
TEMP: .word 35
FLAG: .word 0
