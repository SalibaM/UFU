	.data
n: 	.word 	100  				# valor de entrada
result: .word 	0  				# resultado da função euler phi
msg: 	.asciiz "O resultado é: "

	.text
	.globl main
main:
	la 	$t0, n  			# carrega o endereço de n em $t0
    	lw 	$a0, 0($t0)  			# carrega o valor de n em $a0
    	addi 	$t1, $zero, 1  			# inicializa o contador
    	addi 	$t2, $zero, 0  			# inicializa o resultado

loop:
    	beq 	$t1, $a0, fim  			# if ( n == contador) encerra o loop
    	jal 	mdc  				# chama a função mdc
    	beq 	$v0, 1, incrementar  		# if (mdc(n, i) = 1), incrementa o resultado
    	addi 	$t1, $t1, 1  			# contador++
    	j 	loop				# volta para o começo do loop

incrementar:
    	addi 	$t2, $t2, 1  			# resultado++
    	addi 	$t1, $t1, 1  			# contador++
    	j 	loop				# volta para o loop anterior

fim:
    	la 	$t0, result  			# carrega o endereço de result em $t0
    	sw 	$t2, 0($t0)  			# armazena o resultado em result

    	la 	$a0, msg			# imprime a string (syscall)
    	li	$v0, 4
    	syscall

    	move 	$a0, $t2			# imprime o resultado (syscall)
    	li 	$v0, 1
    	syscall

    	li 	$v0, 10  			# encerra o programa (syscall)
    	syscall

mdc:
    	add 	$t3, $a0, $zero  		# copia n para $t3
    	add 	$t4, $t1, $zero  		# copia i para $t4

mdc_loop:
    	beq 	$t4, $zero, mdc_fim  		# if (i == 0) termina o loop
    	add 	$t5, $t3, $zero  		# copia n para $t5
    	rem 	$t5, $t5, $t4  			# calcula resto da divisão de n por i
    	add 	$t3, $t4, $zero  		# copia i para n
    	add 	$t4, $t5, $zero  		# copia n mod i para i
    	j 	mdc_loop			# volta para o começo do loop

mdc_fim:
    	add 	$v0, $t3, $zero  		# $v0 = resultado
    	jr 	$ra				# retorna o resultado para a função loop
