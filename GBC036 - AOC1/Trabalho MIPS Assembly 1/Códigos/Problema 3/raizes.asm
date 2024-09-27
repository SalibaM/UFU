	.include "macros.asm"		# utilizando as funções read_float, print_str, print_float

	.data
cte4: 	.float	4.0			# define a constante 4

	.text
	.globl main
main:
	read_float($f0)			# lê float do teclado
     	mov.s	$f1, $f0		# $f1 = a
     
     	read_float($f0)			# lê float do teclado
     	mov.s  	$f2, $f0		# $f2 = b
     
     	read_float($f0)			# lê float do teclado
     	mov.s  	$f3, $f0		# $f3 = c
     
     	mtc1   	$zero, $f5		# (fpu) $f5 = 0
     	c.eq.s  0, $f1, $f5		# if (a == 0) flag = 0
     	bc1t  	a_zero         		# if (flag == 0) encerra o programa 
     
     	mul.s   $f0, $f2, $f2   	# b^2
     
     	l.s     $f4, cte4      		# $f4 = 4.0
     
     	mul.s   $f4, $f4, $f1   	# 4 * a
     	mul.s   $f4, $f4, $f3   	# 4 * a * c
     					# delta = b*b - 4*a*c:
     	sub.s   $f0, $f0, $f4   	# $f0 = delta
     
     	c.lt.s 	$f0, $f5   		# if (delta < 0) flag = 0
     	bc1t 	complexo     		# if (flag == 0) pula para a função complexo
     
     	sqrt.s  $f6,$f0     		# $f6 = raiz quadrada de delta
     	sub.s   $f2, $f5, $f2   	# $f2 = -b
     
     					# comparações para regra da tumba:     
     					# comparar b^2 > ac e b>0 para utilizar R1 com forma SEGURA e R2 com TRADICIONAL
     	mul.s   $f13, $f3, $f1		# $f13 = c * a
     	add.s   $f9, $f1, $f1     	# $f9 = 2a
     	add.s   $f14, $f3, $f3    	# $f14 = 2c
     
     	c.le.s  $f13, $f2   		# if (ac <= -b) flag = 0
     	bc1t    primeiro_metodo		# if (flag == 0) pula para a função segundo método
     	j       segundo_metodo		# else pula para a função primeiro método
     
segundo_metodo:
     	add.s   $f7, $f2, $f6     	# $f7 = -b + raiz de delta
     	div.s   $f16, $f7, $f9    	# $f16 = $f7 / 2a (R1 TRADICIONAL)
     	div.s   $f15, $f14, $f7   	# $f15 = 2c / $f7 (R2 FORMA SEGURA)
     
     	j 	imprimir_resultado	# jump para a impressão resultado
    
primeiro_metodo:
     	sub.s   $f7, $f2, $f6     	# $f7 = -b - raiz de delta
     	div.s   $f16, $f14, $f7   	# $f16 = 2c / $f7 (R1 FORMA SEGURA)
     	div.s   $f15, $f7, $f9    	# $f15 = $f7 / 2a (R2 TRADCIONAL)
     
imprimir_resultado:
     	print_str "x1: "
     	mov.s   $f12, $f16   		# $f2 = x1
     	print_float($f12)		# imprime x1
     	print_str "\n"

     	print_str "x2: "
     	mov.s   $f12, $f15   		# $f12 = x2
     	print_float($f12)		# imprime x2
     	print_str "\n"
     	j 	fim			# jump para o fim do programa

complexo:
     	abs.s   $f0, $f0		# módulo de delta
     	sqrt.s  $f6,$f0     		# sqrt(abs(b2-4ac))
     	sub.s   $f2, $f5, $f2		# b = 0 - b
     	add.s   $f9,$f1,$f1     	# 2*a
     	div.s   $f7,$f2,$f9     	# (-b) / 2a
     	div.s   $f8,$f6,$f9     	# (sqrt(abs(b2-4ac))) / 2a
     
     	print_str "x1,2: "
     	mov.s   $f12, $f7   		# $f12 = parte real
     	print_float($f12)		# imprime parte real
     	print_str " +- "
     	mov.s   $f12, $f8   		# $f12 = parte imaginária
     	print_float($f12)		# imprime parte imaginária
     	print_str "i\n"
     	j fim

a_zero:
      	print_str"O coeficiente 'a' nao pode ser zero"
     
fim:
     	li      $v0, 10     		# encerra o programa (syscall)
     	syscall
