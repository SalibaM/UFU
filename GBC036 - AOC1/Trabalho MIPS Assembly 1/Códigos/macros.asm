	.macro print_str (%str)
	.data
myLabel:	.asciiz %str
	.text
    	li 	$v0, 4
    	la 	$a0, myLabel
    	syscall
	.end_macro

	.macro print_float (%x)
	li     $v0, 2  
	syscall
	.end_macro

	.macro read_float (%x)
    	li     $v0, 6
        syscall
	.end_macro
