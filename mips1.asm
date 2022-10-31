 # programa 01
 # x=3
 # y=4
 
 .text
 .globl main
 main:
 addi $s0, $zero, 100000 # x=3
 addi $s1, $zero, 4 # y=4
 sub $s2,$s0, $s1 # z = y + x
 
 .data
 
 