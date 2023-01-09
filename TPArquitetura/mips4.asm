#Programa 04
# Maquina: Frederico Malaquias

.text
.globl main
# registrador $zero

main: 
addi $s0, $zero, 3 # x = 3 
addi $s1, $zero, 4 # y = 4

sll $t0, $s0, 4 
sub $t0, $t0, $s0

sll $t1, $s1, 6
add $t1, $t1, $s1 
add $t1,$t1,$s1
add $t1,$t1,$s1

add $s2, $t0, $t1 # 15x67
sll $s2, $s2, 2






