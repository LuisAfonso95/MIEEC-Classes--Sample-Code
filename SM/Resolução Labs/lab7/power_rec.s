.text
.globl	power
power:	# $a0($4) contém base e $a1($5) o expoente
	add	$sp,$sp,-4	# reserva espaço na pilha para $ra
	sw	$ra,0($sp)	# salvaguarda $ra

	slti	$8,$5,2
	beq	$8,$0,recorre	#salta se m>1
	nop
	addi	$8,$5,-1
	bne	$8,$0,exp0	#salta se m==0
	nop
	add	$2,$4,$0	#m=1, retorna m
	j	fim
	nop
recorre:addi	$5,$5,-1	#decrementa m
	jal	power
	nop
	mult	$2,$4
	mflo	$2
	j	fim
	nop
exp0:	addi	$2,$0,1		#m=0, retorna 1

fim:	lw	$ra,0($sp)	#recupera $ra
	addi	$sp,$sp,4	#limpa stack frame
	jr	$ra
