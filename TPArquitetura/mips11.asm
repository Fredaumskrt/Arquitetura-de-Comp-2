.text
main:

addi $s0, $zero, 0 # A
lw $t0, 0($s0)
loop:
slt $t1, $s0, $s0 # A < 0 = NEGATIVO
sub $t2, $s0, 0
bne $t1, $zero, fim

 	fim:
 .data
