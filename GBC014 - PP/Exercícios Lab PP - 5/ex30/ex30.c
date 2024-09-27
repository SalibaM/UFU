#include <stdio.h>
#include <string.h>

int main(){

    char opcao,caracter1,caracter2;
    char string1[20],string2[500],string3[500];
    int tamanho,tamanho2,i,j,apareceu,encontrou,pos,tam;

    printf("Selecione uma opcao:\n");
    printf("A)Ler uma string S1 de tamanho maximo 20 caracteres.\n");
    printf("B)Imprimir o tamanho da string S1.\n");
    printf("C)Comparar a string S1 com uma nova string S2 fornecida pelo usuario e imprimir o resultado da comparacao.\n");
    printf("D)Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da concatenacao.\n");
    printf("E)Imprimir a string S1 de forma reversa.\n");
    printf("F)Contar quantas vezes um dado caractere aparece na string S1.\n");
    printf("G)Substituir a primeira ocorrencia do caractere C1 da string S1 pelo caractere C2.\n");
    printf("H)Verificar se uma string S2 eh substring de S1.\n");
    printf("I)Retornar uma substring da string S1.\n");

    scanf("%c",&opcao);

    switch(opcao){
        case ('A'):
        printf("Digite uma string de no maximo 20 caracteres:\n");
        setbuf(stdin, NULL);
        fgets(string1,20,stdin);
        printf("A string digitada foi:\n%s",string1);
        break;
        
        case ('B'):
        printf("Digite uma string:\n");
        setbuf(stdin, NULL);
        fgets(string2,500,stdin);
        tamanho=strlen(string2);
        printf("O tamanho dessa string sera:\n%d",tamanho);
        break;

        case ('C'):
        printf("Digite uma string:\n");
        setbuf(stdin, NULL);
        fgets(string2,500,stdin);
        printf("Digite outra string:\n");
        setbuf(stdin, NULL);
        fgets(string3,500,stdin);
        if(strcmp(string2,string3)==0){
            printf("Essas strings sao iguais!\n");
        } else {
            printf("Essas strings sao diferentes!\n");
        }
        break;

        case ('D'):
        printf("Digite uma string:\n");
        setbuf(stdin, NULL);
        fgets(string2,500,stdin);
        printf("Digite outra string:\n");
        setbuf(stdin, NULL);
        fgets(string3,500,stdin);
        strcat(string2,string3);
        printf("A string concatenada sera:\n%s",string2);
        break;

        case ('E'):
        printf("Digite uma string:\n");
        setbuf(stdin, NULL);
        fgets(string2,500,stdin);
        tamanho = strlen(string2);
        printf("Essa string, de forma reversa, sera:\n");
        for(i=tamanho;i>=0;i--){
            printf("%c",string2[i]);
        }
        break;
        
        case ('F'):
        printf("Digite uma string:\n");
        setbuf(stdin, NULL);
        fgets(string2,500,stdin);
        printf("Digite o caracter:\n");
        scanf("%c",&caracter1);
        tamanho=strlen(string2);
        for(i=0;string2[i]!='\0';i++){
            if(string2[i]==caracter1){
                apareceu++;
            }
        }
        printf("Existem %d vezes esse caracter na string digitada.\n",apareceu);
        break;

        case ('G'):
        printf("Digite uma string:\n");
        setbuf(stdin, NULL);
        fgets(string2,500,stdin);
        printf("Digite o caracter que voce quer substituir nessa string:\n");
        setbuf(stdin, NULL);
        scanf("%c",&caracter1);
        printf("Digite o substituto desse caracter:\n");
        setbuf(stdin, NULL);
        scanf("%c",&caracter2);
        tamanho=strlen(string2);
        for(i=0;string2[i]!='\0';i++){
            if(string2[i]==caracter1){
                string2[i]=caracter2;
            } 
        }
        printf("O resultado dessa string sera:\n%s",string2);
        break;

        case('H'): // muito difícil clauclau,que isso...
        printf("Digite uma string:\n");
        setbuf(stdin, NULL);
        fgets(string2,500,stdin);
        printf("Digite a string que voce quer verificar se eh substring da primeira:\n");
        setbuf(stdin, NULL);
        fgets(string3,500,stdin);
        tamanho=strlen(string2);
        tamanho2=strlen(string3);
        encontrou = 0;
        for(i=0;i<tamanho;i++){
            for(j=0;j<tamanho2;j++){
                if(string2[i+j]!=string3[j]){
                    break;
                } else {
                    encontrou = 1;
                }
            }
        }
        if(encontrou==1){
            printf("Essa string eh substring da primeira!\n");
        } else {
            printf("Essa string NAO eh substring da primeira!\n");
        }
        break;

        case('I'):
        printf("Digite uma string:\n");
        setbuf(stdin, NULL);
        fgets(string2,500,stdin);
        printf("Digite a posicao inicial:\n");
        scanf("%d",&pos);
        printf("Digite o tamanho da substring:\n");
        scanf("%d",&tam);
        strncpy(string3,string2+pos,tam);
        string3[tam]='\0';
        printf("Substring: %s\n",string3);
        break;

        default:
        printf("Digite uma opcao valida!");


    }


    return 0;
}