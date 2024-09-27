#include <stdio.h>

int main(){
    int vhorainicial;
    int vmininicial;
    int vseginicial;
    int vhoraduracao;
    int vminduracao;
    int vsegduracao;
    int vhorafinal;
    int vminfinal;
    int vsegfinal;

    printf("Digite o horario de inicio do experimento(horas,minutos e segundos respectivamente):");
    scanf("%d",&vhorainicial);
    scanf("%d",&vmininicial);
    scanf("%d",&vseginicial);

    printf("Digite a duracao do experimento(horas, minutos e segundos respectivamente):");
    scanf("%d",&vhoraduracao);
    scanf("%d",&vminduracao);
    scanf("%d",&vsegduracao);

    vhorafinal = vhorainicial + vhoraduracao;
    vminfinal = vmininicial + vminduracao;
    vsegfinal = vseginicial + vsegduracao;

    printf("O horario de termino do experimento foi:%d hora(s), %d minutos, %d segundos",vhorafinal,vminfinal,vsegfinal);

    return 0;

}