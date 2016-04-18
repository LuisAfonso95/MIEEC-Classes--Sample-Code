	.file	1 "lab6_4a.c"
	.section .mdebug.abi32
	.previous
	.abicalls
	.rdata
	.align	2
$LC0:
	.ascii	"$s2=%d, $s3=%d, $s4=%d\012\000"
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
	li	$2,1			# 0x1
	sw	$2,32($fp)
	li	$2,1			# 0x1
	sw	$2,28($fp)
	li	$2,2			# 0x2
	sw	$2,24($fp)
	b	$L9
	nop

$L3:
	lw	$2,%got($LC0)($28)
	nop
	addiu	$4,$2,%lo($LC0)
	lw	$5,32($fp)
	lw	$6,28($fp)
	lw	$7,24($fp)
	lw	$25,%call16(printf)($28)
	nop
	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$2,28($fp)
	nop
	addiu	$2,$2,1
	sw	$2,28($fp)
	lw	$2,28($fp)
	nop
	slt	$2,$2,26
	bne	$2,$0,$L2
	nop

	lw	$2,24($fp)
	nop
	addiu	$2,$2,1
	sw	$2,24($fp)
$L2:
$L9:
	lw	$2,32($fp)
	nop
	blez	$2,$L5
	nop

	lw	$2,28($fp)
	nop
	slt	$2,$2,26
	bne	$2,$0,$L3
	nop

$L5:
	lw	$3,24($fp)
	li	$2,3			# 0x3
	beq	$3,$2,$L3
	nop

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
