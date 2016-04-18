	.file	1 "lab5_5a.c"
	.section .mdebug.abi32
	.previous
	.abicalls
	.rdata
	.align	2
$LC0:
	.ascii	"s1=%d\012\000"
	.text
	.align	2
	.globl	main
	.ent	main
	.type	main, @function
main:
	.frame	$fp,40,$31		# vars= 8, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	.cprestore	16
	li	$2,9			# s1=9   /   0x9
	sw	$2,24($fp)
	lw	$2,24($fp)
	nop
	slt	$2,$2,9
	beq	$2,$0,$L2		# salta se s1>=9
	nop

	lw	$2,24($fp)
	nop
	addiu	$2,$2,15		# s1=s1+15
	sw	$2,24($fp)
	b	$L4
	nop

$L2:
	lw	$2,24($fp)
	nop
	addiu	$2,$2,-8		# s1=s1-8
	sw	$2,24($fp)
$L4:
	lw	$2,%got($LC0)($28)
	nop
	addiu	$4,$2,%lo($LC0)
	lw	$5,24($fp)
	lw	$25,%call16(printf)($28) # printf(s1)
	nop
	jalr	$25
	nop

	lw	$28,16($fp)
	move	$2,$0
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.ident	"GCC: (GNU) 4.1.2 20061115 (prerelease) (Debian 4.1.1-21)"
