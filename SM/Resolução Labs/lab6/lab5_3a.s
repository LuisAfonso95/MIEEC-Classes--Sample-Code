	.file	1 "lab5_3a.c"
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
	.frame	$fp,48,$31		# vars= 16, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	
	addiu	$sp,$sp,-48
	sw	$31,44($sp)
	sw	$fp,40($sp)
	move	$fp,$sp
	.cprestore	16
	li	$2,10			# 0xa
	sw	$2,28($fp)
	sw	$0,24($fp)
	lw	$2,24($fp)
	nop
	bne	$2,$0,$L2	# if $2!=0
	nop

	lw	$2,28($fp)	# $2=$s0
	nop
	sw	$2,32($fp)
	b	$L4
	nop

$L2:
	li	$2,2			# $2=2   /   0x2
	sw	$2,32($fp)
$L4:
	lw	$2,%got($LC0)($28)
	nop
	addiu	$4,$2,%lo($LC0)
	lw	$5,32($fp)
	lw	$25,%call16(printf)($28)	# printf($s2)
	nop
	jalr	$25
	nop

	lw	$28,16($fp)
	move	$2,$0
	move	$sp,$fp
	lw	$31,44($sp)
	lw	$fp,40($sp)
	addiu	$sp,$sp,48
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.ident	"GCC: (GNU) 4.1.2 20061115 (prerelease) (Debian 4.1.1-21)"
