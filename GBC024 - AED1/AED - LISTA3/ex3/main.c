#include <stdio.h>
#include <stdlib.h>

int pow(int x,int y);

int taylor(int x,int n){

    int resultado=0;
    int i;

    for(i=0;i<=n;i++){
        resultado = resultado + (pow(x,i)/fatorial(i)*1.0);
    }

    return resultado;

}

int fatorial(int n){

    int i;
    int result=1;

    for(i=n;i>0;i--){

        result = result * i;

    }

    return result;

}

int main(){

    int x,n;

    printf("Digite o valor de x em euler:\n");
    scanf("%d",&x);

    printf("Digite o valor de n:\n");
    scanf("%d",&n);

    printf("Resultado : %d",taylor(x,n));



    return 0;
}

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
