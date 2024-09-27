#include <stdio.h>
#include <stdlib.h>

int pow(int x,int y){

    int i=0;
    int eleva=x;

    if(y==0){
        return 1;
    }

    if(y<0){

        y = y * (-1);

        for(i=1;i<y;i++){
            eleva = eleva * x;
        }

        return eleva;

    } else {
        for(i=1;i<y;i++){
        eleva = eleva * x;
    }
    return eleva;

    }



}

int main(){

    int x,y;

    printf("Digite o valor de x:\n");
    scanf("%d",&x);

    printf("Digite o valor elevado:\n");
    scanf("%d",&y);

    if(y<0){
        printf("Resultado: (1/%d)",pow(x,y));
        exit(1);
    }

    printf("Resultado:%d\n",pow(x,y));


    return 0;
}
