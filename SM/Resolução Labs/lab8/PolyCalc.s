.data

.text
.globl PolyCalc

PolyCalc:
#j a
b:
	sll $a0, $a0, 5
	sll $a1, $a1, 3
	sll $a2, $a2, 2
	sll $a3, $a3, 1
	lw $t0, 16($fp)
	
	add $v0, $a0, $a1
	add $v0, $v0, $a2
	add $v0, $v0, $a3
	add $v0, $v0, $t0
	
	jr $ra


a:
	li $t4, 3
	mult $a1, $t4
		mflo $t0
	addu $t1, $a0, $t0

	#sll $t1, $t1, 1 # t1= t1*2
	
	lw $t2, 16($fp)
	li $t4, -2
	mult $a3, $t4
		mflo $t0
	mult $t0, $t2
		mflo $t0
	add $t3, $a2, $t0
	
	mult $t1, $t3
		mflo $v0
		
	sll $v0, $v0, 1 # total*2
	
	jr $ra