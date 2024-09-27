# P2 - avaliação polinomial
	
	.data
coef: 	.word 	2, -11, -7, -27, 88  		# vetor de coeficientes
x: 	.word 	3                        	# valor de x
n: 	.word 	5                        	# ordem do polinômio
result: .word 	0                   		# resultado do cálculo
 
	.text
	.globl main
main:
    	la 	$a0, coef			# carrega o começo do vetor de coeficientes
    	lw 	$a1, n				# carrega n
    	lw 	$a2, x				# carrega x
    	jal 	tradicional 			# chama a função tradicional
    	sw 	$v0, result			# $v0 recebe o resultado
 
   	li 	$v0, 1
    	lw 	$a0, result 			# imprime o resultado (syscall)
    	syscall
    
    	la 	$a0, coef			# carrega o começo do vetor de coeficientes
    	lw 	$a1, n				# carrega n
    	lw 	$a2, x				# carrega x
    	jal 	horner 				# chama a função horner
    	sw 	$v0, result			# $v0 recebe o resultado
 
    	li 	$v0, 1
    	lw 	$a0, result 			# imprime o resultado (syscall)
    	syscall

    	li 	$v0, 10				# termina o programa (syscall)
    	syscall
 
pow: 						# função para calcular a potência
    	move 	$v0, $zero			# $v0 = 0
    	beq 	$a1, $zero, fim_pow		# if (n == 0) encerra o loop
    	li 	$v0, 1				
    	
loop_pow:
    	mul 	$v0, $v0, $a0			# resultado *= coeficiente
    	sub 	$a1, $a1, 1			# n--
    	bnez 	$a1, loop_pow			# if (n != 0) continua no loop
    	
fim_pow:
     	jr 	$ra				# retorna o resultado 

tradicional: 					# função tradicional
	addi	$sp, $sp, -4			# preservar registros dos endereços de retorno
	sw	$ra, 0($sp)
	move 	$t0, $zero  			# resultado = 0
	move 	$t1, $zero  			# contador (i) = 0

loop_trad:
	beq 	$t1, $a1, fim_trad		# if (i == n) encerra o loop
	move 	$a0, $a2  			# base = x
	sub 	$a1, $a1, $t1  			# expoente = n - i
	jal 	pow				# chama a função pow
	move 	$t2, $v0  			# x^(n-i)
	lw 	$t3, 0($a0)     		# coef[i]
	mul 	$t2, $t2, $t3  			# coef[i]*x^(n-i)
	add 	$t0, $t0, $t2  			# resultado += coef[i]*x^(n-i)
	addiu 	$a0, $a0, 4  			# próximo coeficiente
	addiu 	$t1, $t1, 1  			# próximo i
	j 	loop_trad			# continua no loop
	
fim_trad:
	move 	$v0, $t0			# $v0 = resultado
	lw	$ra, 0($sp)			# tratamento dos registros
	addi	$sp, $sp, 4
	jr 	$ra				# retorna o resultado
 
horner: 					# função horner
    	lw 	$t0, 0($a0)  			# resultado = coef[0]
    	addiu 	$a0, $a0, 4  			# próximo coeficiente
    	li 	$t1, 1				# contador (i) = 1

loop_horner:
     	beq 	$t1, $a1, fim_horner		# if (i == n) encerra o loop
     	mul 	$t0, $t0, $a2  			# resultado *= x
     	lw 	$t2, 0($a0)     		# coef[i]
     	add 	$t0, $t0, $t2  			# resultado += coef[i]
     	addiu 	$a0, $a0, 4  			# próximo coeficiente
     	addiu 	$t1, $t1, 1  			# próximo i
     	j 	loop_horner			# continua no loop

fim_horner: 
	move 	$v0, $t0 			# move o resultado para $v0
	jr 	$ra				# retorna o resultado
