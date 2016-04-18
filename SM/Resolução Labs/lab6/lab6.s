	.file	1 "lab6_1.c"
	.section .mdebug.abi32
	.previous
	.abicalls
	.globl	source
	.data
	.align	2
	.type	source, @object
	.size	source, 28
# alocacao de memoria para o vector 'source'
source:
	.word	3
	.word	1
	.word	4
	.word	1
	.word	5
	.word	9
	.word	0
	.rdata
	.align	2
# string usada pelo 'printf()'
$LC0:
	.ascii	"%d values copied\012\000"
	.text
	.align	2
	.globl	main
	.ent	main
	.type	main, @function

# inicio da funcao main() - programa principal
main:
	.frame	$fp,40,$31		# vars= 8, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	
	addiu	$sp,$sp,-40	# aloca 40 bytes de memória na stack
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	.cprestore	16
	sw	$0,24($fp)	# variavel k local usada para guardar $v0; inicializada a zero
	b	$L2
	nop

$L3:
	lw	$5,24($fp)		# $5($a1)=k
	lw	$2,24($fp)		#  $2($v0)=k
	lw	$3,%got(source)($28)	# registo $3 ($v1) e´ ponteiro para 'source'
	sll	$2,$2,2
	addu	$2,$2,$3	# $2($v0)=$3+4*$2
	lw	$4,0($2)	# %4($a0)=source[k]
	lw	$3,%got(dest)($28)	# $3($v1) ponteiro para 'dest'
	sll	$2,$5,2
	addu	$2,$2,$3	# $2=$3+4*$5
	sw	$4,0($2)	# dest[k] = source[k]
	lw	$2,24($fp)	# recupera o valor de $2 ($v0)
	nop
	addiu	$2,$2,1		# $v0++
	sw	$2,24($fp)	# guarda na pilha $v0
$L2:
	lw	$2,24($fp)	# recupera $v0
	lw	$3,%got(source)($28)
	sll	$2,$2,2
	addu	$2,$2,$3	# $2 aponta para source[k]
	lw	$2,0($2)	# $2 = source[k]
	nop			# 'lw' e 'bne' precedem sempre um 'nop' !!!
	bne	$2,$0,$L3	# se $2!=0 continua o ciclo
	nop

	lw	$2,%got($LC0)($28)
	nop
	addiu	$4,$2,%lo($LC0)	# $a0 = ponteiro para string
	lw	$5,24($fp)	# $a1 = k `a saida do ciclo
	lw	$25,%call16(printf)($28)
	nop
	jalr	$25		# chama printf()
	nop

	lw	$28,16($fp)	# repoe $gp
	move	$2,$0		# $v0=0
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main

	.comm	dest,40,4
	.ident	"GCC: (GNU) 4.1.2 20061115 (prerelease) (Debian 4.1.1-21)"
