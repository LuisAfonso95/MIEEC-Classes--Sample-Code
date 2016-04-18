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
	li	$16,1
	li	$17,2

	move	$8,$16
	move	$9,$17
	add	$10,$8,$9
	add	$11,$9,$10
	add	$12,$10,$11
	add	$13,$11,$12
	add	$14,$12,$13
	add	$15,$13,$14
	add	$16,$14,$15

	
	#-------------------------------------------
	#
	#-------------------------------------------
	
	la	$4,str			#passagem parametro para func write
	move	$5,$16
	li	$6,12			# 0xc ultimo parametro passado a func write
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
