# P1 - potenciação, fragmento 1

	.data					# declarar variáveis
x:	.word	2				# defina aqui o valor de x (base)
n:	.word	3				# defina aqui o valor de n (expoente)
result:	.word	1				# resultado inicializado como 1 (fator nulo da multiplicação)

	.text
	.globl expo1
expo1:						# movendo cada variável para seus respectivos registradores
	la	$t0, x				# $t0 recebe o endereço de x
	lw	$a0, 0($t0)			# $a0 recebe o valor apontado por $t0
	la	$t1, n				# $t1 recebe o endereço de n
	lw	$a1, 0($t1)			# $a1 recebe o valor apontado por $t1
	la	$t2, result			# $t2 recebe o endereço de result
	lw	$t2, 0($t2)			# $t2 recebe o valor apontado por $t2
	
	j	teste				# jump para teste
	
while:
	mult	$t2, $a0			# resultado *= x
	mflo	$t2				# LO recebe o resultado da multiplicação
	subi	$a1, $a1, 1			# n--

teste:
	bgtz	$a1, while			# if (n > 0) entre no while
	
	li	$v0, 1				# imprime inteiro na tela (syscall)
	move	$a0, $t2			# move o resultado em $t2 para $a0
	syscall
	
	li	$v0, 10				# encerra o programa (syscall)
	syscall
