	.file	1 "lab5_4a.c"
	.section .mdebug.abi32
	.previous
	.abicalls
	.rdata
	.align	2
$LC0:
	.ascii	"OK\000"
	.align	2
$LC1:
	.ascii	"N\343o\000"
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
	li	$2,10			# 0xa
	sw	$2,24($fp)
	lw	$2,24($fp)
	nop
	blez	$2,$L2		# if $2<=0 salta p/ $L2
	nop

	lw	$2,%got($LC0)($28)
	nop
	addiu	$4,$2,%lo($LC0)
	lw	$25,%call16(puts)($28)
	nop
	jalr	$25		# printf("OK")
	nop

	lw	$28,16($fp)
	b	$L4
	nop

$L2:
	lw	$2,%got($LC1)($28)
	nop
	addiu	$4,$2,%lo($LC1)
	lw	$25,%call16(puts)($28)
	nop
	jalr	$25		# printf("Não")
	nop

	lw	$28,16($fp)
$L4:
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
