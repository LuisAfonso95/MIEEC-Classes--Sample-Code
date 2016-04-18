	.data
	.global str
str:
	.ascii	"valor=%d\012\000"
	.text
	.align	2
	.globl	main
	.ent	main
	.type	main, @function
main:
	.set 	noreorder
	.cpload	$25
	.set 	nomacro
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	sw	$0,24($fp)
	lw	$2,24($fp)

	#-------------------------------------------
	# Inserir codigo
	#-------------------------------------------
	#li	$16,...
	#li	$17,...

	#add	...
	
	#-------------------------------------------
	#
	#-------------------------------------------
	
	la	$4,str			#passagem parametro para printf
	move	$5,$16		#passagem parametro para printf
	la	$25,printf
	jalr	$25
	move	$sp,$fp
	lw 	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	
	.set	macro
	.set 	reorder
	.end	main
