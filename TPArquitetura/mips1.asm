#Programa 01
# Maquina: Frederico Malaquias

.text
.globl main
# registrador $zero

main: 
addi $s0, $zero, 2 #a
addi $s1, $zero, 3 #b
addi $s2, $zero, 4 #c
addi $s3,$zero,  5 #d

add $t0, $s0, $s1 #soma a + b
add $t1, $s2, $s3 # soma c + d
# $t3 = x
sub $t3, $t0, $t1 # resultado de x
# $t4 = y
sub $t4, $s0, $s1 # sub de y
add $t5,$t4, $t3 # -5

sub $s1, $t3,$t5









