#include <stdio.h>
#include <stdlib.h>

struct clientes{

    int cpf;
    char estcivil;
    char nomefilho[50];


}; typedef struct clientes clientes;

int main(){

    int n=0,i=0;
    struct clientes *cliente;
    int opcao,pos=0;
    int filho=0;
    int quantidadefilhos;


    printf("Digite o tamanho do vetor necessario:\n");
    scanf("%d",&n);

    cliente = (clientes*)malloc(n*sizeof(clientes));

    if(cliente==NULL){
        printf("Erro!\n");
        exit(1);
    }

    do{
        printf("Menu do programa:\n\n (1)Inserir dados de novos clientes\n(2)Remover cliente do vetor\n(3)Mostrar todos os CPFs\n(4)Sair do programa\n\n");
        printf("Digite a opcao desejada:\n");
        scanf("%d",&opcao);

        switch(opcao){

        case 1:

            printf("Hora de adicionar novos clientes!\n");

            printf("Qual sera a posicao do cliente no vetor?\n");
            setbuf(stdin,NULL);
            scanf("%d",&pos);

            printf("Digite o CPF do cliente:\n");
            setbuf(stdin,NULL);
            scanf("%d",&cliente[pos].cpf);

            printf("Digite o estado civil do cliente ('S '- Solteiro / 'C' - Casado / 'D' - Divorciado / 'V' - Viuvo):\n");
            setbuf(stdin,NULL);
            scanf("%c",&cliente[pos].estcivil);

            printf("O cliente tem filhos? Digite 1 se ele tiver...\n");
            scanf("%d",&filho);


            if(filho==1){

                printf("Quantos filhos?\n");
                scanf("%d",&quantidadefilhos);

                for(i=0;i<quantidadefilhos;i++){

                    printf("Digite o nome do filho:\n");
                    setbuf(stdin,NULL);
                    fgets(cliente[i].nomefilho,50,stdin);

                }


            } else {

                printf("Beleza!");
            }

            printf("Cliente cadastrado!\n\n");
            break;


        case 2:

            printf("Digite a posicao do vetor que você deseja remover:\n");
            scanf("%d",&pos);

            cliente[pos].cpf = 0;
            cliente[pos].estcivil = '-';

            printf("Cliente removido!\n\n");
            break;

        case 3:

            printf("Lista atualizada de clientes:\n");

            for(pos=0;pos<n-1;pos++){

                printf("CPF: %d\nEstado civil: %c\n",cliente[pos].cpf,cliente[pos].estcivil);
                printf("\n");


            }

            break;

        case 4:

            free(cliente);
            exit(1);
            break;

        }

    } while(opcao!=0);

    return 0;

}
