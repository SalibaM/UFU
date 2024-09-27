#include <stdio.h>

int main(){

    char string[200];
    int i;
    char letrasubstituidamin,letrasubstituidamaiu,letranovamin,letranovamaiu;

    printf("Digite sua string:\n");
    fgets(string,100,stdin);

    printf("Digite a letra que voce quer substituir(minuscula e maiuscula,respectivamente),logo depois,qual voce quer no lugar(minuscula e maiuscula):\n");
    scanf("%c%c%c%c",&letrasubstituidamin,&letrasubstituidamaiu,&letranovamin,&letranovamaiu);

    for(i=0;string[i]!='\0';i++){
        if((string[i]==letrasubstituidamin)){
            string[i]=letranovamin;
        } else {
            if((string[i]==letrasubstituidamaiu)){
                string[i]==letranovamaiu;
            }
        }
    }

    printf("A string nova sera:%s",string);








    return 0;
}