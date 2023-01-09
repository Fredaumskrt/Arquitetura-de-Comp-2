# programa 22
# Sua função deverá criar um vetor que tem início nesse endereço de memória
# (primeiro argumento) e a quantidade de elementos desse vetor dadas pelo segundo argumento.
# Cada elemento do vetor é um elemento da série:
# y[i] = 2i – 1 se i for par;
# y[i] = i se i for impar.
# O valor retornado será a soma de todos os elementos de y[].

# Ass:
# A[0] = $s0
# qtd = $s1
# soma = $s2

.text
.globl main
main:
addi $s0, $zero, 0x1001 # A[0] = 0x0000 1001
sll $s0, $s0, 16 # A[0] = 0x1001 0000
addi $s1, $zero, 10 # qtd = 10

add $a0, $zero, $s0 # a0 = A[0]
add $a1, $zero, $s1 # a1 = 10
addi $t7, $zero, 2 # t7 = 2
jal func 

add $s2, $zero, $v0 # soma = func(A[0], qtd)
j fim

func: 

addi $t0, $zero, 0 # t0 = 0
do:

and $t1, $t0, 1 # t1 = t0 AND 1
bne $t1, $zero, else # if(t1 != 0) -> else
mult $t7, $t0 # 2 * t0
mflo $t3 # t3 = resultado
addi $t3, $t3, -1 # t3 -= 1
sll $t0, $t0, 2 # t0 = 4t0
add $a0, $a0, $t0 # A[0] = A[0 + 4t0]
sw $t3, 0($a0) # A[0 + 4t0] = t3
add $v0, $v0, $t3 # v0 += t3

else:
add $t4, $zero, $t0 # t4 = t0
sll $t0, $t0, 2 # t0 = 4t0
add $a0, $a0, $t0 # A[0] = A[0 + 4t0]
sw $t4, 0($a0) # A[0 + 4t0] = t4
add $v0, $v0, $t4 # v0 += t4

bne $t0, $a1, do # while(t0 != qtd) -> do
jr $ra # return

fim:
