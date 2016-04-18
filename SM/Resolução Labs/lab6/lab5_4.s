	.data
	.global src
	.global dst
	.global str
strs:	.ascii		"OK..e maior q zero\012\000"
strn:	.ascii		"Nao e maior q zero\012\000"
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

	li	$16,4		#$s0
	
	bgtz	$16,label
	nop

	la	$4,strn		#passagem parametro para func write

	j	fim
	nop

	label:
	la	$4,strs		#passagem parametro para func write
	
	fim:	
	la	$25,printf

	

	#-------------------------------------------
	#
	#-------------------------------------------
	
#	la	$4,str			#passagem parametro para func write
#	move	$5,$2
#	li	$6,12			# 0xc ultimo parametro passado a func write
#	la	$25,printf
	jalr	$25
	move	$sp,$fp
	lw 	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	.set	macro
	.set reorder
	.end	main
