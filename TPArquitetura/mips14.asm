# programa 14
# Considere que a partir da primeira posição livre da memória temos um vetor com 100 elementos.
# Escrever um programa que ordene esse vetor de acordo com o algoritmo da bolha. Faça o teste colocando
# um vetor totalmente desordenado e verifique se o algoritmo funciona.

# Ass:
# A[0] = $s0
# i = $s1
# j = $s2
# A[i] = $s3
# A[i + 1] = $s4
# aux = $s5

.text
.globl main
main:
addi $s0, $zero, 0x1001 # A[0] = 0x0000 1001
sll $s0, $s0, 16 # A[0] = 0x1001 0000

addi $s1, $zero, 0 # i = 0
addi $s2, $zero, 1 # j = 1

addi $t0, $zero, 100 # t0 = 100
addi $t1, $zero, 99 # t1 = 99

loop1:
slt $t2, $t0, $s2 # if(100 < j) t2 = 1
bne $t2, $zero, fim # if(t2 != 0) -> fim
addi $s2, $s2, 1 # j++

loop2:
slt $t3, $s1, $t1 # if(i < 99) t3 = 1
beq $t3, $zero, loop1 # if(t3 == 0) -> loop1

sll $t4, $s1, 2 # t4 = 4i
add $t4, $s0, $t4 # t4 = A[0 + 4i]
addi $t5, $t4, 4 # t5 = 4i + 1 
lw $s3, 0($t4) # s3 = A[i] 
lw $s4, 0($t5) # s4 = A[i + 1] 

slt $t6, $s4, $s3 # if (A[i + 1] < A[i]) t6 = 1
addi $s1, $s1, 1 # i++
beq $t6, $zero, loop2 # if(t6 == 0) -> loop2
lw $s5, 0($t4) # aux = A[i]
sw $s3, 0($t5) # A[i] = A[i + 1]
sw $s5, 0($t5) # A[i + 1] = aux

j loop2
fim:
