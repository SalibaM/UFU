#include <stdio.h>

int eh_palindromo(int num) {
    int inverso = 0, original = num;
    while (num != 0) {
        inverso = inverso * 10 + num % 10;
        num /= 10;
    }
    return original == inverso;
}

int main() {
    int num1, num2, produto, max_palindromo = 0;
    for (num1 = 100; num1 <= 999; num1++) {
        for (num2 = 100; num2 <= 999; num2++) {
            produto = num1 * num2;
            if (eh_palindromo(produto) && produto > max_palindromo) {
                max_palindromo = produto;
            }
        }
    }
    printf("O maior numero palindromo feito a partir do produto de dois numeros de 3 digitos eh: %d\n", max_palindromo);
    return 0;
}
