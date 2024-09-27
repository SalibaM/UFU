#include <stdio.h>
#include <math.h>

int main(){

    int x1,x2,a,b,c,delta,quadradob,braizdeltapos,braizdeltaneg,dobroa;

    printf("Digite, respectivamente,o valor de a, b e c da equacao do segundo grau:");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    quadradob = b*b;
    delta = quadradob - (4*a*c);
    braizdeltapos = -b + sqrt(delta);
    braizdeltaneg = -b - sqrt(delta);
    dobroa = 2*a;



    if(a==0){
        printf("Nao e equacao de segundo grau.");
    } else {
        if(delta < 0){
            printf("Nao existe raiz.");
        } else{
            if(delta>0){
                x1 = braizdeltapos / dobroa;
                x2 = braizdeltaneg / dobroa;
                printf("As raizes reais dessa equacao sao, respectivamente:%d e %d",x1,x2);
            } else{
                if(delta==0){
                    x1 = braizdeltapos / dobroa;
                    printf("A unica raiz real dessa equacao eh %d",x1);
                } 

            }
        }

    }
    return 0;

}