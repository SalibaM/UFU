#include <stdio.h>
#include <stdlib.h>

int ordenar (int *x,int *y,int *z,int *maior,int *medio,int *menor){

    if(*x>*y){
        if(*y>*z){
            *maior = *x;
            *medio = *y;
            *menor = *z;
        }
    }

    if(*z>*y){
        if(*y>*x){
           *maior = *z;
           *medio = *y;
           *menor = *x;
        }
    }

    if(*y>*z){
       if(*z>*x){
          *maior = *y;
          *medio = *z;
          *menor = *x;
       }
    }

    if(*x>*z){
        if(*z>*y){
          *maior = *x;
          *medio = *z;
          *menor = *y;

        }
    }

    if(*y>*x){
        if(*x>*z){
          *maior = *y;
          *medio = *x;
          *menor = *z;

        }
    }

    if(*z>*x){
        if(*x>*y){
          *maior = *z;
          *medio = *x;
          *menor = *y;

        }
    }

    if(*x!=*y){
        if(*y!=*z){
            return 0;
        }
    }

    if(*x==*y){
        if(*y==*z){
            return 1;
        }
    }

}

int main(){

    int x,y,z,maior=0,medio=0,menor=0;

    printf("Digite tres valores(x, y e z):\n");
    scanf("%d%d%d",&x,&y,&z);

    ordenar(&x,&y,&z,&maior,&medio,&menor);

    if(ordenar(&x,&y,&z,&maior,&medio,&menor)==1){
        printf("Os valores sao iguais!\n");
        return 0;
    }

    if(ordenar(&x,&y,&z,&maior,&medio,&menor)==0){
        printf("Os valores sao diferentes!\n");
    }

    printf("Maior:%d\n",maior);
    printf("Meio-termo:%d\n",medio);
    printf("Menor:%d\n",menor);

    return 0;



}