	.data
	.global str
str:	.ascii		"$s1=%d\012\000"
str2:	.ascii		"O ciclo terminou com: $s1=%d\012\000"
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

	li	$17,60				# Inicia contador $s1
	li	$18,10				# Limite para paragem do contador ($s2 = 10)
for:
	la	$4,str	#printf: 1º parametro 
	move	$5,$17	#printf: 2º parametro
	lw	$25,%call16(printf)($28)	#carrega endereço do printf
	nop		
	jalr	$25				#chama printf
	nop
	lw	$28,16($sp)			#restaura o program counter
	move	$2,$0				#assegura que $v0=0

	addi	$17,$17,-1			#decrementa contador
	slti	$8,$17,1
	beq	$8,$0,for	# continua ciclo se $17>=1 <=> $17>0
	nop

        la      $4,str2 #printf: 1º parametro 
        move    $5,$17  #printf: 2º parametro                                   
        lw      $25,%call16(printf)($28) 
        nop                
        jalr    $25                             #chama printf                 
        nop
        lw      $28,16($sp)	#restaura o program counter   
        move    $2,$0           #assegura que $v0=0


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
