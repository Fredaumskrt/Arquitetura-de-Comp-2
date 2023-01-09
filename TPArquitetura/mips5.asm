#Programa 08
# Maquina: Frederico Malaquias

.text
.globl main
# registrador $zero

main: 
ori $8, $0, 0x12345678 # x = maior inteiro

srl $9, $8, 24

#10
srl $10, $8, 16
sll $10, $10, 24
sll $10, $10, 24

#11
srl $11, $8, 8
sll $11, $11, 24
sll $11, $11, 24

#12
sll $12, $8, 24
srl $12, $12, 24