	.data
	.global src
	.global dst
	.global str
str:	.ascii		"$s1=%d\012\000"
src: 	.word		3,1,4,1,5,9,0
dst:	.word		0,0,0,0,0,0,0
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
	li	$16,1		#$s0
	li	$19,1		#$s3
	
	beq	$19,$0,label
	nop

	li	$17,2
	j	fim
	nop

	label:
	move	$17,$16

	fim:	

	#-------------------------------------------
	#
	#-------------------------------------------
	
	la	$4,str			#passagem parametro para func write
	move	$5,$17
	li	$6,12			# 0xc ultimo parametro passado a func write
	la	$25,printf
	jalr	$25
	move	$sp,$fp
	lw 	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	.set	macro
	.set reorder
	.end	main
