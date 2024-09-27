#include <stdio.h>

struct dma {
    int dia;
    int mes;
    int ano;
};

int diasNoMes(int mes, int ano) {
    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0))
        return 29;

    return diasNoMes[mes - 1];
}

int calcularDiferencaDias(struct dma data1, struct dma data2) {
    int diasTotal = 0;

   
    struct dma dataInicio, dataFim;
    if (data1.ano < data2.ano || (data1.ano == data2.ano && data1.mes < data2.mes) ||
        (data1.ano == data2.ano && data1.mes == data2.mes && data1.dia < data2.dia)) {
        dataInicio = data1;
        dataFim = data2;
    } else {
        dataInicio = data2;
        dataFim = data1;
    }

    
    while (dataInicio.ano < dataFim.ano || dataInicio.mes < dataFim.mes || dataInicio.dia < dataFim.dia) {
        diasTotal++;
        dataInicio.dia++;

        if (dataInicio.dia > diasNoMes(dataInicio.mes, dataInicio.ano)) {
            dataInicio.dia = 1;
            dataInicio.mes++;

            if (dataInicio.mes > 12) {
                dataInicio.mes = 1;
                dataInicio.ano++;
            }
        }
    }

    return diasTotal;
}

int main() {
    struct dma data1, data2;

    printf("Digite a primeira data: ");
    scanf("%d %d %d", &data1.dia, &data1.mes, &data1.ano);

    printf("Digite a segunda data: ");
    scanf("%d %d %d", &data2.dia, &data2.mes, &data2.ano);

    int diferencaDias = calcularDiferencaDias(data1, data2);

    printf("O numero de dias entre as duas datas eh: %d\n", diferencaDias);

    return 0;
}
