#include <stdio.h>

struct produto {
    int codigo;
    char nome[51];
    int quantidade;
    float preco;
};

int main() {
    int N;
    printf("Digite a quantidade de produtos a serem cadastrados: ");
    scanf("%d", &N);

    struct produto produtos[N];

    for (int i = 0; i < N; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);
        printf("Nome: ");
        scanf(" %[^\n]", produtos[i].nome);
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
    }

    int indice_maior_preco = 0;
    int indice_maior_quantidade = 0;

    for (int i = 1; i < N; i++) {
        if (produtos[i].preco > produtos[indice_maior_preco].preco) {
            indice_maior_preco = i;
        }

        if (produtos[i].quantidade > produtos[indice_maior_quantidade].quantidade) {
            indice_maior_quantidade = i;
        }
    }

    printf("\nProduto com maior preco de venda:\n");
    printf("Codigo: %d\n", produtos[indice_maior_preco].codigo);
    printf("Nome: %s\n", produtos[indice_maior_preco].nome);
    printf("Quantidade: %d\n", produtos[indice_maior_preco].quantidade);
    printf("Preco: %.2f\n", produtos[indice_maior_preco].preco);

    printf("\nProduto com maior quantidade disponivel no estoque:\n");
    printf("Codigo: %d\n", produtos[indice_maior_quantidade].codigo);
    printf("Nome: %s\n", produtos[indice_maior_quantidade].nome);
    printf("Quantidade: %d\n", produtos[indice_maior_quantidade].quantidade);
    printf("Preco: %.2f\n", produtos[indice_maior_quantidade].preco);

    return 0;
}
