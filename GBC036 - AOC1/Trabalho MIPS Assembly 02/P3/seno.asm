		.data
x:          	.float 40.0			# ângulo em graus
pi:         	.float 3.141592
divisor:    	.float 180.0
precisao:   	.float 0.00001
um:         	.float 1.0
resultado: 	.asciiz "seno(x) = "

		.text
main:
                                        	# conversão de ângulo para radianos
    	lwc1    $f0, x                     	# atribui o valor do ângulo em graus
    	lwc1    $f1, pi                     	# atribui o valor de pi
    	lwc1    $f10, divisor
    	mul.s   $f0, $f0, $f1               	# graus * pi
	div.s   $f0, $f0, $f10               	# divide o ângulo por 180 graus
                                       	
senox: 						# cálculo do seno de x
    	mtc1    $zero, $f5                   	# inicializa $f5 com zero para ser usado posteriormente
    	add.s   $f2, $f0, $f5                	# carrega o resultado com x em $f2
    	lwc1    $f7, precisao                	# carrega o valor de "precisao" em $f7, para posterior comparação
    	li      $t0, 3                       	# inicializa o fator de x^3
    	lwc1    $f11, um                     	# inicializa o sinal (alternância)

loop:
    	mul.s   $f4, $f0, $f0                	# cálculo x^2
    	mul.s   $f4, $f4, $f2                	# cálculo x^3
    	mtc1    $t0, $f3                      	# carrega o fator de x^3 para um registrador de ponto flutuante
    	div.s   $f4, $f4, $f3                	# divide por (3!)
    	mul.s   $f4, $f4, $f1                	# aplica o sinal (pi)
   	mul.s   $f4, $f4, $f11                	# aplica o sinal alternante
    	sub.s   $f2, $f2, $f4
    	addi    $t0, $t0, 2                  	# incrementa o fator de x^3
    	neg     $t1, $t1                      	# alterna o sinal
    	c.lt.s  $f2, $f7                     	# compara o termo atual com a precisão especificada
    	bc1t    fimLoop                     	# se for menor que a precisão, termina o loop
    	j       loop                          	# senão, volta ao início do loop

fimLoop:
    	li      $v0, 4                        	# imprimir string (syscall)
    	la      $a0, resultado       
    	syscall

    	li      $v0, 2                        	# imprimir float (syscall)
    	mov.s   $f12, $f0                    
    	syscall

        li      $v0, 10                       	# encerrar o programa (syscall)
    	syscall