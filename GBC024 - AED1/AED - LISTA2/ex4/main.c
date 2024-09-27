#include <stdio.h>
#include <stdlib.h>

int main(){

    int i=0,j=0;
    int *p,*p2;
    int n,contador=0,tamanhofinal;

    printf("Digite o tamanho do vetor:");
    scanf("%d",&n);

    p = (int *)malloc(n*sizeof(int));

    if(p==NULL){
        printf("Erro!\n");
        exit(1);
    }

    for(i=0;i<n;i++){
        printf("Digite o %d numero:",i+1);
        scanf("%d",&p[i]);
    }

    for(i=0;i<n;i++){
        if(p[i] % 2 != 0){
            contador++;
        }
    }

    tamanhofinal = n - contador;

    p2 = (int *)malloc(tamanhofinal*sizeof(int)); //"realoquei" criando outro vetor do tamanho certo

    if(p2==NULL){
        printf("Erro!\n");
        exit(1);
    }

    for(i=0;i<n;i++){
        if(p[i]%2 == 0){
            p2[j] = p[i];
            j++; //evita que ultrapasse o tamanho de p2
        }
    }

    printf("O vetor sem elementos impares sera:\n");

    for(i=0;i<tamanhofinal;i++){
        printf("%d ",p2[i]);
    }

    free(p);
    free(p2);



    return 0;
}
