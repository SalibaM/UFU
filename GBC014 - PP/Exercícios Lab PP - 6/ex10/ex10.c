#include <stdio.h>
#include <string.h>

struct pessoa {
    char nome[50];
    char endereco[100];
    char telefone[15];
};

int main() {
    struct pessoa pessoas[5];
    struct pessoa temp;
    int i, j;

    printf("Entre com os dados das pessoas:\n");
    for (i = 0; i < 5; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: ");
        fflush(stdin);
        fgets(pessoas[i].nome,50,stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';
        printf("Endereco: ");
        fflush(stdin);
        fgets(pessoas[i].endereco,100,stdin);
        pessoas[i].endereco[strcspn(pessoas[i].endereco, "\n")] = '\0';
        printf("Telefone: ");
        fgets(pessoas[i].telefone,15,stdin);
        pessoas[i].telefone[strcspn(pessoas[i].telefone, "\n")] = '\0';
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4 - i; j++) {
            if (strcmp(pessoas[j].nome, pessoas[j + 1].nome) > 0) {
                temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
            }
        }
    }

    printf("Dados das pessoas em ordem alfabetica:\n");
    for (i = 0; i < 5; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s", pessoas[i].nome);
        printf("Endereco: %s", pessoas[i].endereco);
        printf("Telefone: %s", pessoas[i].telefone);
    }

    return 0;
}
