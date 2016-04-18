	.data
	.global str
str1:	.ascii		"caso 1\012\000"
str2:	.ascii		"caso 2\012\000"
str3:	.ascii		"caso 'default'\012\000"
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

	#li	$18,1	# $s2=1
	#li	$18,2	# $s2=2
	li	$18,0	# $s2=0

tcaso1:	addi	$8,$18,-1
	bne	$8,$0,tcaso2	# salta se $18!=1
	nop
caso1:	la      $4,str1 	# 1º parametro para printf()
        lw      $8,%call16(printf)($28) #carrega endereço do printf em $t0
        nop
        jalr    $8      #corre printf()
        nop
        lw      $28,16($sp)     #restaura o program counter
        move    $2,$0
	j	endswitch
	nop
tcaso2: addi	$8,$18,-2
	bne	$8,$0,default	# salta se $18!=2
	nop
caso2:  la      $4,str2         # 1º parametro para printf()
        lw      $8,%call16(printf)($28) #carrega endereço do printf em $t0
        nop
        jalr    $8      #corre printf()
        nop
        lw      $28,16($sp)     #restaura o program counter
        move    $2,$0
        j       endswitch 
        nop
default:la      $4,str3         # 1º parametro para printf()
        lw      $8,%call16(printf)($28) #carrega endereço do printf em $t0
        nop
        jalr    $8      #corre printf()
        nop
        lw      $28,16($sp)     #restaura o program counter
        move    $2,$0
endswitch: nop

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
