	.file	1 "sum_v1.c"
	.section .mdebug.abi32
	.previous
	.abicalls
	.rdata
	.align	2
$LC0:
	.ascii	"Enter the first number: \000"
	.align	2
$LC1:
	.ascii	"%d\000"
	.align	2
$LC2:
	.ascii	"Enter the second number: \000"
	.align	2
$LC3:
	.ascii	"The sum of %d with %d is %d \012\000"
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
	lw	$2,%got($LC0)($28)
	nop
	addiu	$4,$2,%lo($LC0)
	lw	$25,%call16(printf)($28)
	nop
	jalr	$25
	nop

	lw	$28,16($fp)
	addiu	$3,$fp,28
	lw	$2,%got($LC1)($28)
	nop
	addiu	$4,$2,%lo($LC1)
	move	$5,$3
	lw	$25,%call16(scanf)($28)
	nop
	jalr	$25
	nop

	lw	$28,16($fp)
	nop
	lw	$2,%got($LC2)($28)
	nop
	addiu	$4,$2,%lo($LC2)
	lw	$25,%call16(printf)($28)
	nop
	jalr	$25
	nop

	lw	$28,16($fp)
	addiu	$3,$fp,32
	lw	$2,%got($LC1)($28)
	nop
	addiu	$4,$2,%lo($LC1)
	move	$5,$3
	lw	$25,%call16(scanf)($28)
	nop
	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$3,28($fp)
	lw	$2,32($fp)
	nop
	addu	$2,$3,$2
	sw	$2,24($fp)
	lw	$3,28($fp)
	lw	$6,32($fp)
	lw	$2,%got($LC3)($28)
	nop
	addiu	$4,$2,%lo($LC3)
	move	$5,$3
	lw	$7,24($fp)
	lw	$25,%call16(printf)($28)
	nop
	jalr	$25
	nop

	lw	$28,16($fp)
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
