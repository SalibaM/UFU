#include <stdio.h>

int main() {
    char string1[100];
    char string2[100];

    printf("Digite a primeira string: ");
    scanf("%s", string1);

    printf("Digite a segunda string: ");
    scanf("%s", string2);

    char *str1 = string1;
    char *str2 = string2;

    while (*str1 != '\0') {
        char *temp1 = str1;
        char *temp2 = str2;

        // Verifica se a substring ocorre a partir da posição atual
        while (*temp1 == *temp2 && *temp1 != '\0' && *temp2 != '\0') {
            temp1++;
            temp2++;
        }

        // Se a segunda string chegou ao fim, significa que encontramos a substring
        if (*temp2 == '\0') {
            printf("A segunda string ocorre dentro da primeira.\n");
            return 0;
        }

        str1++;
    }

    printf("A segunda string não ocorre dentro da primeira.\n");
    return 0;
}
