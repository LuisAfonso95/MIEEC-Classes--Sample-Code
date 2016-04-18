	.data
	.global str
str:	.ascii		"$s0=%d\012\000"
	.text
	.align	2
	.globl	main
	.ent	main
	.type	main, @function
main:
	.set	noreorder
	.cpload	$25
	.set nomacro

	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	sw	$0,24($fp)
	lw	$2,24($fp)

	#------------------------------------------
	#
	#-------------------------------------------

	li	$16,0	# $s0=0
	#li	$16,1	# $s0=1

	bne	$16,$0,else
	nop
	li	$16,-2
	j 	endif
	nop
else:	li	$16,3
endif:	la	$4,str	# 1º parametro para printf()
	move	$5,$16	# 2º parametro para printf()
	lw	$8,%call16(printf)($28)	#carrega endereço do printf em $t0
	nop		
	jalr	$8	#corre printf()
	nop
	lw	$28,16($sp)	#restaura o program counter que está a seguir a $ra,str e inteiro
	move	$2,$0		#assegura que o valor de retorno do printf é 0

	#-------------------------------------------
	#
	#-------------------------------------------

	move	$sp,$fp
	lw 	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	.set	macro
	.set reorder
	.end	main
