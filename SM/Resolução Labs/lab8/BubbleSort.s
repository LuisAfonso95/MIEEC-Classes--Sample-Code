	.file	1 "BubbleSort.c"
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 1
	.abicalls
	.text
	.align	2
	.globl	BubbleSort
	.set	nomips16
	.ent	BubbleSort
	.type	BubbleSort, @function
BubbleSort:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-8
	sw	$fp,4($sp)
	move	$fp,$sp
	sw	$4,8($fp)
	li	$2,5			# 0x5
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	BubbleSort
	.size	BubbleSort, .-BubbleSort
	.ident	"GCC: (Debian 4.4.5-8) 4.4.5"
