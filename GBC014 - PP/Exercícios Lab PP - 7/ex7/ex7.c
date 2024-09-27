#include <stdio.h>

int main(){

    int x,y,z;
    int *a,*b,*c;
    int maior=0,medio=0,menor=0,*endmaior,*endmedio,*endmenor;
     
    printf("Digite o primeiro,segundo e terceiro numero, respectivamente:\n");
    scanf("%d%d%d",&x,&y,&z);

    a = &x;
    b = &y;
    c = &z;

    if (*a > *b && *a > *c) {
        maior = *a;
        endmaior = a;
        if (*b > *c) {
            medio = *b;
            endmedio = b;
            menor = *c;
            endmenor = c;
        } else {
            medio = *c;
            endmedio = c;
            menor = *b;
            endmenor = b;
        }
    } else if (*b > *a && *b > *c) {
        maior = *b;
        endmaior = b;
        if (*a > *c) {
            medio = *a;
            endmedio = a;
            menor = *c;
            endmenor = c;
        } else {
            medio = *c;
            endmedio = c;
            menor = *a;
            endmenor = a;
        }
    } else {
        maior = *c;
        endmaior = c;
        if (*a > *b) {
            medio = *a;
            endmedio = a;
            menor = *b;
            endmenor = b;
        } else {
            medio = *b;
            endmedio = b;
            menor = *a;
            endmenor = a;
        }
    }
    
    printf("Os numeros em ordem crescente serao: (%d,%d,%d) :)\n",menor,medio,maior);
    printf("Os enderecos dos tres numeros, respectivamente, serao: %p, %p, %p",endmenor,endmedio,endmaior);




    return 0;
}