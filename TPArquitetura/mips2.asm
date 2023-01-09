#Programa 02
# Maquina: Frederico Malaquias

.text
.globl main
# registrador $zero

main: 
addi $s0, $zero, 1 #x
addi $s1, $zero, 15

add $t0,$s0,$s0
add $t1, $t0, $s0
add $t2, $t1,$s0
add $t3, $t2, $s0

add $t4, $t3,$s1 







