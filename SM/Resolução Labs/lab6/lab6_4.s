	.data
	.global str
str:	.ascii		"$s2=%d, $s3=%d, $s4=%d\012\000"
str2:	.ascii		"O ciclo terminou com: $s2=%d, $s3=%d, $s4=%d\012\000"
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

	li	$18,1	# $s2=1
	li	$19,1	# $s3=1
	li	$20,2	# $s4=2
ciclo:	addi	$8,$20,-3
	beq	$8,$0,iteracao	# salta se #20=3
	nop
	slti	$8,$18,1
	bne	$8,$0,fim	# salta se $18<1 <=> $18<=0
	nop
	slti	$8,$19,26
	beq	$8,$0,fim	#salta se $19>=26 <=> $19>25
	nop
iteracao:la      $4,str 	# 1º parametro para printf()
	move	$5,$18		# 2º parametro
	move	$6,$19		# 3º parametro
	move	$7,$20		# 4º parametro
        lw      $25,%call16(printf)($28) #carrega endereço do printf
        nop
        jalr    $25      	#chama printf()
        nop
        lw      $28,16($sp)     #restaura o program counter
	nop
        move    $2,$0

	addi	$19,$19,1	# $19=$19+1
	slti	$8,$19,26
	bne	$8,$0,fimif	# salta se $19<26 <=> $19<=25
	nop
	addi	$20,$20,1	# $20=$20+1
fimif:	j	ciclo
	nop
fim:	la      $4,str2         # 1º parametro para printf()
        move    $5,$18          # 2º parametro
        move    $6,$19          # 3º parametro
        move    $7,$20          # 4º parametro
        lw      $25,%call16(printf)($28) #carrega endereço do printf
        nop
        jalr    $25             #chama printf()
        nop
        lw      $28,16($sp)     #restaura o program counter
        nop
        move    $2,$0

	#-------------------------------------------
	#
	#-------------------------------------------

	move	$sp,$fp
	lw 	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	.set	macro
	.set reorder
	.end	main
