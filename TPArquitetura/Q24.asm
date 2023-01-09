.data

x: .word 0x10010008
y: .word 10

.text
add $s0, $0, 0x1001
sll $s0, $s0, 16

lw $a0, 0($s0)
lw $a1, 4($s0)

jal funcao1
j fim

funcao1:

addi $t0, $0, 30
slt $t1, $t0, $a1		# 30 < a1 | a1 > 30
beq $t1, $0, continue
addi $a1, $0, 30

continue:

# ------------------------------------------------------------- #

addi $s1, $0, 0			# i = 0

loop:

# mem add
sll $s2, $s1, 2			# s2 = 4i
add $s2, $s2, $a0		# s2 += a0

# stack (reserve)
addi $sp, $sp, -8
sw $a0, 4($sp)
sw $ra, 0($sp)

# parity
addi $t0, $0, 2
div $s1, $t0
mfhi $t0			# t0 = i % 2
beq $t0, $0, epar		# if(i % 2 == 0) epar;

# impar
add $a0, $0, $s1		# a0 = i
jal quadrado
add $s3, $0, $v0		# s3 = i ^ 2
j store

# par
epar:
add $a0, $0, $s1		# a0 = i
jal quadrado
add $s3, $0, $v0		# s3 = i²
sll $s3, $s3, 1			# s3 = 2i²
add $t0, $0, $s1		# t0 = i
sll $t0, $t0, 1			# t0 = i²
add $s3, $s3, $t0		# s3 = 2i² + 2i
addi $s3, $s3, 1		# s3 += 1

# store
store:
sw $s3, 0($s2)			# mem[i] = s3
add $s4, $s4, $s3		# s4 = s4 + s3

# stack (restore)
lw $a0, 4($sp)
lw $ra, 0($sp)
addi $sp, $sp, 8

# loop controls
addi $s1, $s1, 1
bne $s1, $a1, loop

# ------------------------------------------------------------- #

add $v0, $0, $s4		# v0 = s4
jr $ra

# ------------------------------------------------------------- #

quadrado:

mult $a0, $a0
mflo $v0
jr $ra

# ------------------------------------------------------------- #

fim: