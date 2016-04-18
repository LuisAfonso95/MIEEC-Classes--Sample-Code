	.data
	
	.text
	.globl Mandelbrot

	
		
Mandelbrot:

		
b:
addi $sp, $sp, -4	#reserva espaço para 1 inteiros
sw $ra, 0($sp)		#guarda registo de retorno
addi $t0,$a1, -1	#faz n-1
bne $t0, -1, else	#se t0 não for -1, salta (tem de fazer n+1)
move $v0, $a0		#mete z inicial em v0
addi $sp, $sp, 4	#restaura stack
jr $ra

else:
move $a1, $t0		#mete n-1 em a1, parametro para proxima chamada
jal Mandelbrot		#chama-se a si mesma 
mult $v0, $v0		#
mflo $v0		#z^2
addu $v0, $v0, $a0	# + z0

lw $ra, 0($sp)		#restaura ra respetivo
addi $sp, $sp, 4	#restaura a stack
jr $ra			#salta para retorno	#salta para retorno	
		
		
		
		
		
		
		
		
		
#==============================================
a:
move $v0, $a0 #$v0 é valor, a0 é z0

li $t0, 0
loop:

mult $v0, $v0
mflo $v0
add $v0, $v0, $a0

addi $t0, $t0, 1 #i++
bne $t0, $a1, loop # i != n entoa vai para loop

jr $ra
