.data

.text
.globl program_asm

program_asm:


3:

addi $sp, $sp, -4 #reserva de espaço na stack
sw $ra, 0($sp) #guarda registo de retorno
jal BubbleSort
lw $ra, 0($sp)
addi $sp, $sp, 4
jr $ra

2:
#aqui carrega todos os valores da tabela para parametros			
move $t0,$a0 #Muda o endereço da tabela para t0	
lw $a0, 0($t0)
lw $a1, 4($t0)
lw $a2, 8($t0)
lw $a3, 12($t0)
lw $t1, 16($t0)	#nao ha mais registo parametro por isso guarda-se em t1

addi $sp, $sp, -8 #reserva de espaço na stack
sw $ra, 4($sp) #guarda registo de retorno
sw $fp, 0($sp) #guarda frame pointer anterior

addi $sp, $sp, -20 #reserva de espaço na stack para o $fp
move $fp, $sp
sw $t1, 16($fp) #guarda 5º parametro. Usa-se o frame pointer por ser fixo
		#o 5º parametro é sempre em 16. 16-arg4, 20-arg5, etc..
		#é sempre nesses valores mesmo sendo um char que so ocupa 1byte em vez de 4bytes.
#jal PolyCalc


addi $sp, $sp, 20
lw $ra, 4($sp)
lw $fp, 0($sp)
addi $sp, $sp, 8

jr $ra
