#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct conj{

    int *vetconj;

}Conjunto;


int main() {

    Conjunto *c1 = criarconjunto();
    Conjunto *c2 = criarconjunto();
    Conjunto *c_aux = criarconjunto();

    int opcao;
    int numero_remover;
    int numero_verificar;
    int tamanho;

    do {
        printf("\nOpções:\n");

        printf("1. Inserir membros no conjunto 1\n");

        printf("2. Inserir membros no conjunto 2\n");

        printf("3. Remover membro de um conjunto\n");

        printf("4. Verificar membro em um conjunto\n");

        printf("5. Uniao entre conjuntos\n");

        printf("6. Intersecao entre conjuntos\n");

        printf("7. Diferenca entre conjuntos\n");

        printf("8. Sair\n");

        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                inserir_membros_conjunto(c1);
                break;

            case 2:

                inserir_membros_conjunto(c2);
                break;

            case 3:

                printf("Digite o numero a ser removido:\n");
                scanf("%d",&numero_remover);

                remove_membros_conjunto(c1,numero_remover);

                remove_membros_conjunto(c2,numero_remover);

                break;

            case 4:

                printf("Digite o numero a verificar:\n");
                scanf("%d",&numero_verificar);
                if (membro_presente(c1,numero_verificar)==1)
                    printf("%d está presente em C1.\n",numero_verificar);

                if (membro_presente(c2,numero_verificar)==1)
                    printf("%d está presente em C2.\n",numero_verificar);

                break;

            case 5:

                c_aux = uniao_entre_conjuntos(c1,c2);

                printf("Uniao entre conjuntos:\n");

                tamanho = sizeof(c_aux->vetconj)/sizeof(c_aux->vetconj[0]);

                for (int i = 0; i < tamanho; i++) {
                    printf("%d",c_aux->vetconj[i]);
                }

                printf("\n");
                break;

            case 6:

                c_aux = interseccao_entre_conjuntos(c1, c2);
                printf("Intersecao entre conjuntos:");

                tamanho = sizeof(c_aux->vetconj)/sizeof(c_aux->vetconj[0]);

                for (int i = 0; i <tamanho; i++) {
                    printf("%d ", c_aux->vetconj[i]);
                }

                printf("\n");
                break;

            case 7:

                c_aux = diferenca_entre_conjuntos(c1,c2);

                printf("Diferenca entre conjuntos:");

                tamanho = sizeof(c_aux->vetconj)/sizeof(c_aux->vetconj[0]);

                for (int i = 0; i < tamanho; i++) {
                    printf("%d ", c_aux->vetconj[i]);
                }
                printf("\n");
                break;

            case 8:

                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 8);

    free(c1->vetconj);
    free(c1);
    free(c2->vetconj);
    free(c2);
    if (c_aux!=NULL) {
        free(c_aux->vetconj);
        free(c_aux);
    }

    return 0;
}
