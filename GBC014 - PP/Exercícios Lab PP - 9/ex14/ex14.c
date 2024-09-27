#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int raizes(float a,float b,float c,float *raiz1,float *raiz2){

    int delta,quadradodelta,quadradob,quatroac;
    if(a==0){
        *raiz1= ((-c)/b);
        return 1;
    }

    if(a>=0){
        quatroac = 4*a*c;
        quadradob= b*b;
        delta = quadradob-quatroac;
        quadradodelta = sqrt(delta);
        *raiz1= ((-b)+(quadradodelta))/(2*a);
        *raiz2= ((-b)-(quadradodelta))/(2*a);
    }

    if(*raiz1==*raiz2){
        return 2;
    } else {
        return 3;
    }
}

int main(){

    float a,b,c,raiz1,raiz2;

    printf("Digite A,B e C da equacao do segundo grau que sera resolvida:\n");
    scanf("%f%f%f",&a,&b,&c);

    if(a<0){
        printf("Pelo valor de A ser menor que 0, essa equacao nao tem raiz real!");
        exit(1);
    }

    if(raizes(a,b,c,&raiz1,&raiz2)==1){
        printf("Existe uma raiz real:%.2f\n",raiz1);
    } else {
        if(raizes(a,b,c,&raiz1,&raiz2)==2){
            printf("Existem duas raizes,e elas sao iguais:%.2f, %.2f.",raiz1,raiz2);
        } else {
            printf("Existem duas raizes diferentes,e elas sao:%.2f, %.2f.",raiz1,raiz2);

        }
    }

    return 0;


}