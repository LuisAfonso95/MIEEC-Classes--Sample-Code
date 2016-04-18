.text
.globl somapond

somapond:
	addi	$sp,$sp,-4	#reserva espaço na pilha
	sw	$fp,0($sp)
	addi	$fp,$sp,4	#aponta $fp para o inicio do stack frame
	lw	$12,16($fp)	#valor de x5 (usa $t0-$t4)
	# compilador aloca espaço para os 4 primeiros parâmetros!!!
	add	$8,$4,$0	#valor de x1
	sll	$8,$8,4		#16*x1
	add	$9,$5,$0	#x2
	sll	$9,$9,3		#8*x2
	add	$10,$6,$0	#x3
	sll	$10,$10,2	#4*x3
	add	$11,$7,$0	#x4
	sll	$11,$11,1	#2*x4
	add	$2,$8,$9	#$v0=(16*x1)+8*x2
	add	$2,$2,$10	#(16*x1+8*x2)+4*x3
	add	$2,$2,$11	#(16*x1+8*x2+4*x3)+2*x4
	add	$2,$2,$12	#(16*x1+8*x2+4*x3+2*x4)+x5

	lw	$fp,0($sp)
	addi	$sp,$sp,4

	jr	$ra
