#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int i;
    int lot[6];
    int mine[6];
    int count=0;
    int *p;

    printf("Digite os 6 numeros gerados pela loteria:\n");
    for(i=0;i<6;i++){
        scanf("%d",&lot[i]);
    }
    
    printf("Digite os 6 numeros do seu bilhete:\n");
    for(i=0;i<6;i++){
        scanf("%d",&mine[i]);
    }

    for(i=0;i<6;i++){
        if(lot[i]==mine[i]){
            count++;
        }
    }

    p = (int*)malloc(count*sizeof(int));

    for(i=0;i<count;i++){
        if(lot[i]==mine[i]){
            *(p+i)=lot[i];
        }
    }

    if(count==0){
        printf("NAO GANHOU :(");
        exit(1);
    }


    printf("NUMEROS GANHADORES:\n");
    for(i=0;i<count;i++){
        printf("%d",*(p+i));
    }

    free(p);

    return 0;

}