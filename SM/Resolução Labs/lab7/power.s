.text
.globl	power
power:					# $a0 contém base e $a1 o expoente
	addi $2,$0,1		# prepara para retornar 1 (expoente <=0)
	slti $8,$5,1		# $t0 = 1 se $a1 < 1
	bne $8,$0,L1
	addi $5,$5,-1
	add $2,$0,$4		# prepara para retornar base $a0 (expoente 1)
L2:	beq $5,$0,L1
	mult $2,$4
	mflo $2
	addi $5,$5,-1
	j L2
L1:	jr $31
	
