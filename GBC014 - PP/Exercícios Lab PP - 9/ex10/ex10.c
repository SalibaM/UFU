#include <stdio.h>

int somaarray(int *array1,int *array2,int *array3,int n1,int n2){
    int i;

    if(n1==n2){
        for(i=0;i<n1;i++){
        array3[i] = array1[i] + array2[i];
    }
    return 1;

    } else {
        return 0;
    }
}

int main(){

    int n1,n2;

    printf("Digite o tamanho do primeiro array:\n");
    scanf("%d",&n1);

    printf("Digite o tamanho do segundo array:\n");
    scanf("%d",&n2);

    int array1[n1],array2[n2],array3[n1];
    int i;

    printf("Digite os %d primeiros valores do primeiro array:\n",n1);
    for(i=0;i<n1;i++){
        setbuf(stdin,NULL);
        scanf("%d",&array1[i]);
    }

    printf("Digite os %d primeiros valores do segundo array:\n",n2);
    for(i=0;i<n2;i++){
        setbuf(stdin, NULL);
        scanf("%d",&array2[i]);
    }

    if(somaarray(array1,array2,array3,n1,n2)==1){

    printf("O array com a soma do primeiro e do segundo sera:\n");
    for(i=0;i<n1;i++){
        printf("%d, ",array3[i]);
    }
    } else {
        printf("Nao e possivel realizar a operacao :(");
    }

    return 0;


}