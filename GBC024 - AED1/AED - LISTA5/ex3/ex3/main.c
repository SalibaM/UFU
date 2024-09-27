#include <stdio.h>
#include <stdlib.h>

int main(){

    int i,j,k=0,l=0;
    int **mat;
    int *vet;
    int m=0,n=0;

    vet = (int *)calloc(1,sizeof(int));

    if(vet==NULL){
        printf("Erro!");
        exit(1);
    }


    printf("Digite as dimensoes da matriz:\n");
    scanf("%d%d",&m,&n);

    mat = (int **)calloc(m,sizeof(int));

    if(mat==NULL){
        printf("Erro!");
        exit(1);
    }

    for(i=0;i<m;i++){
        mat[i]=(int *)calloc(n,sizeof(int));
    }

    printf("Preencha sua matriz:\n");

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            vet[k]=mat[i][j];
            k++;
            vet = (int *)realloc(vet,(k+1)*sizeof(int));

        }
    }

    for(i=0;i<k;i++){
        for(j=(i+1);j<k;j++){
            if(vet[i]==vet[j]){
                for(l=j;l<k;l++){
                    vet[l]=vet[l+1];
                }
                j--;
                k--;
                vet = (int *)realloc(vet,k*sizeof(int));
            }
        }
    }

    printf("O vetor resultante da matriz,e sem repeticoes, sera:\n");

    printf("-> (");

    for(i=0;i<k;i++){
        printf(" %d ",vet[i]);
    }

    for(i=0;i<m;i++){
        free(mat[i]);
    }

    printf(") <-");

    free(mat);

    free(vet);

    return 0;
}
