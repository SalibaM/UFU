#include <stdio.h>
#include <string.h>

int main(){

    char string[100];
    int i,qntd;
    char subst;

    qntd=0;

    printf("Digite uma string:\n");
    fgets(string, 100,stdin);

    for(i=0;string[i]!='\0';i++){
        if(string[i]=='a'){
            qntd++;
        }
        if(string[i]=='e'){
            qntd++;
        }
        if(string[i]=='i'){
            qntd++;
        }
        if(string[i]=='o'){
            qntd++;
        }
        if(string[i]=='u'){
            qntd++;
        }
    }

    printf("Existem %d vogais nessa string\n",qntd);

    printf("Digite uma vogal ou uma consoante para substituir todas as vogais:\n");
    scanf("%c",&subst);

    for(i=0;string[i]!='\0';i++){
        if(string[i]=='a'){
            string[i]=subst;
        }
        if(string[i]=='e'){
            string[i]=subst;
        }
        if(string[i]=='i'){
            string[i]=subst;
        }
        if(string[i]=='o'){
            string[i]=subst;
        }
        if(string[i]=='u'){
            string[i]=subst;
        }
    }

    printf("%s",string);




                  

    return 0;
}