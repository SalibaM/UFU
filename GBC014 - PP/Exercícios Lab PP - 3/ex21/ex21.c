#include <stdio.h>

int eh_primo(int num) {
    int i;
    if (num < 2) {
        return 0;
    }
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int contar_primos(int a, int b) {
    int i, contar = 0;
    for (i = a; i <= b; i++) {
        if (eh_primo(i)) {
            contar++;
        }
    }
    return contar;
}

int main() {
    int a, b, contar;
    printf("Digite dois numeros a e b, separados por um espaco: ");
    scanf("%d %d", &a, &b);
    contar = contar_primos(a, b);
    printf("Existem %d numeros primos entre %d e %d\n", contar, a, b);
    return 0;
}
