#include <stdio.h>

struct horario{
    int hora;
    int minutos;
    int segundos;
};

struct data{
    int dia;
    int ano;
    char mes[200];
};
struct compromisso{
    int dia,ano;
    char mes[200];
    int hora,minutos,segundos;
    char descricao[1000];

};


int main(){
    return 0;
}