	.data
	.global src
	.global dst
	.global str
str:	.ascii		"numero de elementos=%d\012\000"
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
	# CODE TO BE ANALYSED
	#-------------------------------------------
	la      $8,src
	la      $9,dst
loop:	lw	$3,0($8)      # read next word from source
	beq	$3,$0,loopend
	nop	#ATENÇÃO: o beq demora 2 ciclos e executa a instrução imediatamente a seguir, antes de saltar.

	addi    $2,$2,1		# increment count words copied
	sw      $3,0($9)	# write to destination

	# addi	$8,$8,1		# advance pointer to next source
	addi	$8,$8,4		# está 4 bytes à frente
	# addi	$9,$9,1		# advance pointer to next dest
	addi	$9,$9,4		# está 4 bytes à frente

	# bne 	$3,$0,loop  # loop if word copied not zero
	j loop
	loopend:
	#-------------------------------------------
	#
	#-------------------------------------------
	
	la	$4,str			#passagem parametro para func write
	move	$5,$2
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
