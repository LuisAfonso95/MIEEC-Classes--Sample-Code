	.data
	.global str
str:	.ascii		"Conta %d\012\000"
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
	#
	#-------------------------------------------

	li	$17,0				# Inicializa contador $s1 = 0
	li	$18,10				# Limite para paragem do contador ($s2 = 10)
for:
	la	$4,str				#carrega primeiro parametro do printf em $a0
	move	$5,$17				#carrega segundo parametro do printf no $a1


	lw	$25,%call16(printf)($28)	#carrega endereço do printf em $t9
	nop		
	jalr	$25				#corre printf e guarda em $ra o valor $pc+8
	nop
	lw	$28,16($sp)			#restaura o program counter que está a seguir a $ra,str e inteiro
	move	$2,$0				#assegura que o valor de retorno do printf é 0

	addi	$17,$17,1			#incrementa contador
	sub	$19,$18,$17			#subtrai inteiro actual pela condicao de paragem para verificar 0
	bgtz	$19,for				#se é maior q zero, continua ciclo
	nop


	#-------------------------------------------
	#
	#-------------------------------------------

	li	$6,12	

	move	$sp,$fp
	lw 	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	.set	macro
	.set reorder
	.end	main
