#include <stdio.h>

int main(){

    int mat[2][2],mat2[2][2],mat3[2][2],mat4[2][2],mat5[2][2];
    int i,j,k,l;
    int opcao;
    float constante;

    printf("Digite valores de uma matriz 2x2:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&mat[i][j]);
        }

    }
    printf("Digite valores de uma segunda matriz 2x2:\n");
    for(k=0;k<2;k++){
        for(l=0;l<2;l++){
            scanf("%d",&mat2[k][l]);
        }

    }

    printf("Escolha uma opcao:\n1)Somar as duas matrizes.\n2)Subtrair a primeira matriz da segunda.\n3)Adicionar uma constante as duas matrizes.\n4)Imprimir as matrizes.\n");
    scanf("%d",&opcao);
    switch(opcao){

        case 1:
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                mat3[i][j] = mat[i][j] + mat2[i][j];
            }
        }
        printf("A soma dessas matrizes sera a matriz:\n");
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                printf("%d",mat3[i][j]);
            }
        if(j==2){
            printf("\n");
        }
        }
        break;

        case 2:
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                mat3[i][j] = mat2[i][j] - mat[i][j];
            }
        }
        printf("A subtracao dessas matrizes sera a matriz:\n");
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                printf("%d",mat3[i][j]);
            }
        if(j==2){
            printf("\n");
        }
        }
        break;
        
        case 3:
        printf("Escolha uma constante(valor):\n");
        scanf("%f",&constante);
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                mat4[i][j]=(constante*mat[i][j]);
                mat5[i][j]=(constante*mat2[i][j]);
            }
        }
        printf("As matrizes resultantes serao:\n");
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                printf("%d",mat4[i][j]);
            }
        if(j==2){
            printf("\n");
        }
        }
        printf("\n");
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                printf("%d",mat5[i][j]);
            }
        if(j==2){
            printf("\n");
        }
        }
        break;
        
        case 4:
        printf("As duas matrizes impressas serao:\n");
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                printf("%d",mat[i][j]);
            }
        if(j==2){
            printf("\n");
        }
        }
        
        printf("\n");

        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                printf("%d",mat2[i][j]);
            }
        if(j==2){
            printf("\n");
        }
        }
        break;
    }

    
    return 0;
}