#include <stdio.h>
#include <stdbool.h>

bool eh_primo(long long int n) {
    if (n < 2) {
        return false;
    }
    for (long long int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long int sum = 0;
    for (long long int i = 2; i < 2000000; i++) {
        if (eh_primo(i)) {
            sum += i;
        }
    }
    printf("A soma de todos os numeros primos abaixo de 2 milhoes eh %lld\n", sum);
    return 0;
}