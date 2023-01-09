#Programa 03
# Maquina: Frederico Malaquias

.text
.globl main
# registrador $zero

main: 
addi $s0, $zero, 3 #x
addi $s1, $zero, 4 #y
add $s2, $zero, 1  # aux
# 15*x = 45
add $t0, $s1, $s0 # 7
add $t1, $s1, $t0 # 11
add $t2, $t1, $t0 # 18
add $t3, $t2, $t2 # 36
add $t4, $t3, $t0 # 43
add $t5, $t4, $s0 # 46
sub $t6, $t5, $s2 # 45

#67*y = 268
add $t7, $t6,$t5  # 91
add $t0, $t7, $t7 # 182
add $t1, $t0, $t7 # 273

sub $t2, $t1, $s1
sub $t3, $t2, $s2 # 268

add $t4, $t6, $t3 # 313
add $t5, $t4, $t4
add $t6, $t5, $t4
add $t7, $t6, $t4





