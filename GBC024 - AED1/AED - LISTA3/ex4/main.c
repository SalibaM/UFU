#include <stdio.h>
#include <stdlib.h>

int quoc(int a,int b,int *quociente,int *resto){

    if(b==0){
        return -1;
    } else {

        *quociente = a/b;
        *resto = a%b;

        return 0;
    }


}

int main(){

    int a=0,b=0,quociente=0;
    int resto=0;

    printf("Digite o valor de a:\n");
    scanf("%d",&a);

    printf("Digite o valor de b:\n");
    scanf("%d",&b);

    printf("\n");

    if(quoc(a,b,&quociente,&resto)==-1){
        printf("Divisao impossivel de ser realizada. Tente novamente...\n");
        exit(1);
    } else {

        printf("O quociente dessa divisao sera %d.\n",quociente);
        printf("O resto dessa divisao sera %d.\n",resto);

    }

    return 0;

}
