#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

typedef struct Palavra palavra;

palavra *criarstring();

void preencherstring(palavra *str);

int tamanhostring(palavra *str);

int ocorrenciastring(palavra *str,char caractere);

void exibirstring(palavra *str);







#endif // PROTOTIPOS_H_INCLUDED
