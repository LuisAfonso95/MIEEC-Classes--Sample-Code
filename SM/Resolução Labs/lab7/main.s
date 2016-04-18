	.file	1 "main.c"
	.section .mdebug.abi32
	.previous
	.abicalls
	.rdata
	.align	2
$LC0:
	.ascii	"Error: missing parameters\012\012Usage: somapond x1 x2 x"
	.ascii	"3 x4 x5\012\000"
	.align	2
$LC1:
	.ascii	"f(%d,%d,%d,%d,%d) = 16*%d+8*%d+4*%d+2*%d+%d = %d\012\012"
	.ascii	"\000"
	.text
	.align	2
	.globl	main
	.ent	main
	.type	main, @function
main:
	.frame	$fp,104,$31		# vars= 32, regs= 3/0, args= 48, gp= 8
	.mask	0xc0010000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	
	addiu	$sp,$sp,-104
	sw	$31,96($sp)
	sw	$fp,92($sp)
	sw	$16,88($sp)
	move	$fp,$sp
	.cprestore	48
	sw	$4,104($fp)
	sw	$5,108($fp)
	lw	$2,104($fp)
	nop
	slt	$2,$2,6
	beq	$2,$0,$L2
	nop

	lw	$2,%got($LC0)($28)
	nop
	addiu	$4,$2,%lo($LC0)
	lw	$25,%call16(puts)($28)
	nop
	jalr	$25
	nop

	lw	$28,48($fp)
	li	$4,-1			# 0xffffffffffffffff
	lw	$25,%call16(exit)($28)
	nop
	jalr	$25
	nop

$L2:
	sw	$0,60($fp)
	b	$L4
	nop

$L5:
	lw	$16,60($fp)
	lw	$2,60($fp)
	nop
	sll	$2,$2,2
	move	$3,$2
	lw	$2,108($fp)
	nop
	addu	$2,$3,$2
	addiu	$2,$2,4
	lw	$2,0($2)
	nop
	move	$4,$2
	lw	$25,%call16(atoi)($28)
	nop
	jalr	$25
	nop

	lw	$28,48($fp)
	move	$4,$2
	sll	$2,$16,2
	addiu	$3,$fp,56
	addu	$2,$2,$3
	sw	$4,8($2)
	lw	$2,60($fp)
	nop
	addiu	$2,$2,1
	sw	$2,60($fp)
$L4:
	lw	$2,60($fp)
	nop
	slt	$2,$2,5
	bne	$2,$0,$L5
	nop

	# *******************************
	# Chamada de somapond()
	lw	$3,64($fp)
	lw	$5,68($fp)
	lw	$6,72($fp)
	lw	$7,76($fp)
	lw	$2,80($fp)
	nop
	sw	$2,16($sp)	# escreve 5º parametro na stack
	move	$4,$3
	lw	$25,%call16(somapond)($28)
	nop
	jalr	$25
	nop

	lw	$28,48($fp)
	sw	$2,56($fp)
	lw	$9,64($fp)
	lw	$10,68($fp)
	lw	$11,72($fp)
	lw	$2,76($fp)
	lw	$3,80($fp)
	lw	$4,64($fp)
	lw	$5,68($fp)
	lw	$6,72($fp)
	lw	$7,76($fp)
	lw	$8,80($fp)
	sw	$2,16($sp)
	sw	$3,20($sp)
	sw	$4,24($sp)
	sw	$5,28($sp)
	sw	$6,32($sp)
	sw	$7,36($sp)
	sw	$8,40($sp)
	lw	$2,56($fp)
	nop
	sw	$2,44($sp)
	lw	$2,%got($LC1)($28)
	nop
	addiu	$4,$2,%lo($LC1)
	move	$5,$9
	move	$6,$10
	move	$7,$11
	lw	$25,%call16(printf)($28)
	nop
	jalr	$25
	nop

	lw	$28,48($fp)
	lw	$2,56($fp)
	move	$sp,$fp
	lw	$31,96($sp)
	lw	$fp,92($sp)
	lw	$16,88($sp)
	addiu	$sp,$sp,104
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.ident	"GCC: (GNU) 4.1.2 20061115 (prerelease) (Debian 4.1.1-21)"
