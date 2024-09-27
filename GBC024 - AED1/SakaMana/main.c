#include "restaurante.h"
#include "cliente.h"
#include "prato.h"
#include "pedidos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

// retorno -2 -> lista nao criada
// retorno -1 -> lista vazia
// retorno  0 -> operação realizada
// retorno -3 - > valores invalidos

int confereCPF(char* cpf);
int confereEmail(char *email);
int confereSenha(char *senha);
int confereCNPJ(char *cnpj);


void mostraCategoria(char *categoria);
void escondeSenha(char *senha);
void CenterText(const char* text);

int main ()
{
    setlocale(LC_ALL, "Portuguese");

    int menu_inicial, menu_cliente_inicio, menu_cliente, menu_restaurante_inicio, menu_restaurante;
    int retorno, opcao, codigo, quantidade;
    char aux[15], categoria[30];
    Cliente auxC;
    Restaurante auxR;
    Prato auxP;

    ListaC *lc;
    ListaR *lr;
    struct lista_p *lp;

    lc = criarC();
    lr = criarR();
    lp = criarP();

    do //menu
    {
        CenterText(" ######     ###    ##    ##    ###    ##     ##    ###    ##    ##    ###   ");
        printf("\n");
        CenterText("##    ##   ## ##   ##   ##    ## ##   ###   ###   ## ##   ###   ##   ## ##  ");
        printf("\n");
        CenterText("##        ##   ##  ##  ##    ##   ##  #### ####  ##   ##  ####  ##  ##   ## ");
        printf("\n");
        CenterText(" ######  ##     ## #####    ##     ## ## ### ## ##     ## ## ## ## ##     ##");
        printf("\n");
        CenterText("      ## ######### ##  ##   ######### ##     ## ######### ##  #### #########");
        printf("\n");
        CenterText("##    ## ##     ## ##   ##  ##     ## ##     ## ##     ## ##   ### ##     ##");
        printf("\n");
        CenterText(" ######  ##     ## ##    ## ##     ## ##     ## ##     ## ##    ## ##     ##");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");


        CenterText("================== MENU ==================\n");
        CenterText("1.Cliente.\n");
        CenterText("2.Restaurante.\n");
        CenterText("0.Sair.\n");

        CenterText("Digite sua opcao:");
        scanf("%d",&menu_inicial);

        system("cls");
        switch(menu_inicial)
        {
            case 0:
                CenterText("Saindo...\n");
                break;

            case 1:
                do
                {
                    CenterText("================== MENU CLIENTE ==================\n");
                    CenterText("1.Login.\n");
                    CenterText("2.Cadastro.\n");
                    CenterText("0.Sair.\n");

                    CenterText("Digite sua opcao:");
                    scanf("%d",&menu_cliente_inicio);

                    system("cls");
                    switch(menu_cliente_inicio)
                    {
                        case 0:
                            break;

                        case 1:
                            do{
                                CenterText("E-mail: ");
                                fflush(stdin);
                                fgets(auxC.email,50,stdin);
                                auxC.email[strcspn(auxC.email,"\n")]='\0';
                                retorno = confereEmail(auxC.email);
                                if(retorno){
                                    CenterText("E-mail inválido! Digite novamente.\n\n");
                                }
                                else if(procuraEmailCliente(lc,auxC.email)!=0){
                                    retorno = 1;
                                    CenterText("E-mail não cadastrado! Digite novamente.\n\n");
                                }
                            }while(retorno);
                            buscaItemCliente(lc,auxC.email,&auxC);
                            do{
                                CenterText("Senha: ");
                                escondeSenha(aux);
                                aux[strcspn(aux,"\n")]='\0';
                                retorno = confereSenha(aux);
                                if(retorno){
                                    CenterText("A senha deve conter pelo menos um caratere maiúsculo, um número e um caractere especial! Digite novamente.\n\n");
                                }
                                else if(strcmp(aux, auxC.senha)!=0){
                                    CenterText("Senha incorreta! Digite novamente!\n");
                                    retorno = 1;
                                }
                            }while(retorno);

                            //login aceito

                            do
                            {
                                system("cls");
                                CenterText("-> Bem vindo ");printf("%s\n", auxC.nome);
                                CenterText("1.Ver restaurantes.\n");
                                CenterText("2.Ver pratos.\n");
                                CenterText("3.Ver carrinho.\n");
                                CenterText("4.Ver meus pedidos.\n");
                                CenterText("5.Alterar cadastro.\n");
                                CenterText("6.Excluir conta.\n");
                                CenterText("0.Sair.\n");

                                CenterText("Digite sua opcao:");
                                scanf("%d",&menu_cliente);

                                system("cls");
                                switch(menu_cliente)
                                {
                                    case 0: break;

                                    case 1:

                                        do{
                                            mostraCategoria(categoria);
                                            system("cls");
                                            CenterText("================== RESTAURANTES ==================\n\n");
                                            mostrarRestaurante(lr, categoria);
                                            opcao =0;
                                            if(listaVaziaR(lr)!=0){
                                                CenterText("Deseja ver algum dos cardápios? \n");
                                                CenterText("1 - Sim\n");
                                                CenterText("0 - Não\n");
                                                CenterText("opção: ");
                                                scanf("%d", &opcao);
                                                switch(opcao){
                                                    case 0: break;
                                                    case 1:
                                                        CenterText("Escolha o número do cardápio: ");
                                                        scanf("%d", &opcao);
                                                        retorno = buscaCodigoRestaurante(lr, opcao, &auxR);
                                                        system("cls");
                                                        if(retorno){
                                                            CenterText("ERRO: opção inválida!, digite novamente.\n");
                                                            opcao = 1;
                                                            break;
                                                        }
                                                        else{
                                                            do{
                                                                CenterText("================== CARDÁPIO ==================\n");
                                                                mostrarPratos(auxR.cardapio);
                                                                if(listaVaziaP(auxR.cardapio)!=0){
                                                                    CenterText("Deseja adicionar algum dos pratos aos carrinho? \n");
                                                                    CenterText("1 - Sim\n");
                                                                    CenterText("0 - Não\n");
                                                                    CenterText("opção: ");
                                                                    scanf("%d", &opcao);
                                                                    switch(opcao){
                                                                        case 0: break;
                                                                        case 1:
                                                                            CenterText("Escolha o número do prato: ");
                                                                            scanf("%d", &opcao);
                                                                            CenterText("Digite a quantidade: ");
                                                                            scanf("%d", &quantidade);
                                                                            buscaPrato(lr,opcao,&auxR);
                                                                            retorno = buscaItemPrato(auxR.cardapio,opcao,&auxP);
                                                                            system("cls");
                                                                            if(retorno){
                                                                                CenterText("ERRO: opção inválida!, digite novamente.\n");
                                                                                opcao = 1;
                                                                                break;
                                                                            }
                                                                            else{
                                                                               auxP.quantidade = quantidade;
                                                                               retorno = inserirPrato(auxC.carrinho, auxP);
                                                                               if(retorno){
                                                                                     CenterText("ERRO: Não foi possível fazer o pedido.\n");
                                                                               }
                                                                               else{
                                                                                    CenterText("Pedido realizado!.\n");
                                                                               }
                                                                            }
                                                                    }
                                                                    CenterText("Deseja ver os pratos novamente?\n");
                                                                    CenterText("1 - Sim\n");
                                                                    CenterText("0 - Não\n");
                                                                    CenterText("opção: ");
                                                                    scanf("%d", &opcao);
                                                                    system("cls");
                                                                    }
                                                            }while(opcao);
                                                        }
                                                }
                                                CenterText("Deseja ver os restaurantes novamente?\n");
                                                CenterText("1 - Sim\n");
                                                CenterText("0 - Não\n");
                                                CenterText("opção: ");
                                                scanf("%d", &opcao);
                                                system("cls");
                                            }
                                        }while(opcao);

                                        CenterText("Pressione qualquer tecla para voltar: ");
                                        fflush(stdin);
                                        getc(stdin);
                                        system("cls");

                                    break;

                                    case 2:


                                        do{
                                            CenterText("================== PRATOS ==================\n");
                                            int i;
                                            mostrarTodosPratos(lr, &i);
                                            opcao = 0;
                                            if(i!=0){
                                                CenterText("\n\nDeseja adicionar algum dos pratos aos pedidos? \n");
                                                CenterText("1 - Sim\n");
                                                CenterText("0 - Não\n");
                                                CenterText("opção: ");
                                                scanf("%d", &opcao);
                                                switch(opcao){
                                                    case 0: break;
                                                    case 1:
                                                        CenterText("Escolha o número do prato: ");
                                                        fflush(stdin);
                                                        scanf("%d", &opcao);
                                                        CenterText("Digite a quantidade: ");
                                                        scanf("%d", &quantidade);
                                                        buscaPrato(lr,opcao,&auxR);
                                                        retorno = buscaItemPrato(auxR.cardapio,opcao,&auxP);
                                                        system("cls");
                                                        if(retorno){
                                                            CenterText("ERRO: opção inválida!, digite novamente.\n");
                                                            opcao = 1;
                                                            break;
                                                        }
                                                        else{
                                                            auxP.quantidade = quantidade;
                                                           retorno = inserirPrato(auxC.carrinho, auxP);
                                                           if(retorno){
                                                                 CenterText("ERRO: Não foi possível fazer o pedido.\n");
                                                           }
                                                           else{
                                                                CenterText("Pedido realizado!.\n");
                                                           }
                                                        }
                                                }
                                                CenterText("Deseja ver os pratos novamente?\n");
                                                CenterText("1 - Sim\n");
                                                CenterText("0 - Não\n");
                                                CenterText("opção: ");
                                                scanf("%d", &opcao);
                                                system("cls");
                                            }
                                        }while(opcao);

                                        CenterText("Pressione qualquer tecla para voltar: ");
                                        fflush(stdin);
                                        getc(stdin);
                                        system("cls");

                                        break;

                                    case 3:
                                        CenterText("================== CARRINHO ==================\n");
                                        mostrarPedidosCliente(auxC.carrinho);
                                        float a = totalCarrinho(auxC.carrinho);
                                        CenterText("\n\nValor total do carrinho: R$ ");printf("%.2f\n", a);
                                        opcao = 1;
                                        while(opcao && (listaVaziaP(auxC.carrinho)==-1)){
                                            CenterText("Deseja remover algum item do carrinho? \n");
                                            CenterText("1 - Sim\n");
                                            CenterText("0 - Não\n");
                                            CenterText("opção: ");
                                            scanf("%d", &opcao);
                                            switch(opcao){
                                            case 0:
                                                break;
                                            case 1:
                                                CenterText("Digite o número do item para remover: ");
                                                scanf("%d",&opcao);
                                                retorno = buscaItemPrato(auxC.carrinho,opcao, &auxP);
                                                if(retorno==0){
                                                    retorno = removerPrato(auxC.carrinho,auxP);
                                                    if(retorno==0){
                                                        opcao = 0;
                                                        system("cls");
                                                        CenterText("Pedido removido com sucesso!\n");
                                                    }
                                                    else{
                                                        opcao = 1;
                                                        system("cls");
                                                        CenterText("ERRO: não foi possivel remover o pedido.\n");
                                                    }
                                                }
                                                else{
                                                    system("cls");
                                                    CenterText("ERRO: opção inválida!\n");
                                                }
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("ERRO: opção inválida!\n");
                                            }

                                        }

                                        opcao = 1;
                                        while(opcao && (listaVaziaP(auxC.carrinho)!=0)){
                                            CenterText("Deseja finalizar a compra?\n");
                                            CenterText("1 - Sim\n");
                                            CenterText("0 - Não\n");
                                            CenterText("opção: ");
                                            scanf("%d", &opcao);
                                            switch(opcao){
                                            case 0:
                                                break;
                                            case 1:
                                                while(listaVaziaP(auxC.carrinho)==-1){
                                                    retornaPrato(auxC.carrinho, &auxP);
                                                    buscaCodigoRestaurante(lr,auxP.cod_restaurante,&auxR);
                                                    inserirPedido(auxR.pedidos,auxC,auxP);
                                                    lp = auxC.pedidos_realizados;
                                                    inserirPrato(lp,auxP);
                                                    removerPrato(auxC.carrinho,auxP);
                                                }
                                                if(retorno==0){
                                                    opcao = 0;
                                                    system("cls");
                                                    CenterText("Pedido realizado com sucesso!\n");
                                                }
                                                else{
                                                    system("cls");
                                                    CenterText("ERRO: não foi possível realizar o pedido!\n");
                                                }
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("ERRO: opção inválida!\n");
                                            }
                                        }
                                        CenterText("Pressione qualquer tecla para voltar: ");
                                        fflush(stdin);
                                        getc(stdin);
                                        system("cls");

                                        break;
                                    case 4:
                                        CenterText("================== PEDIDOS EM PREPARO ==================\n");
                                        mostrarPedidosCliente(auxC.pedidos_realizados);
                                        CenterText("\n================== PEDIDOS QUE SAIRAM PARA ENTREGA ==================\n");
                                        mostrarPedidosCliente(auxC.pedidos_entregues);

                                        opcao = 1;
                                        while(opcao && (listaVaziaP(auxC.pedidos_entregues)==-1)){
                                            CenterText("\nRecebeu algum dos pedidos acima?\n");
                                            CenterText("1 - Sim\n");
                                            CenterText("0 - Não\n");
                                            CenterText("opção: ");
                                            scanf("%d", &opcao);
                                            switch(opcao){
                                            case 0:
                                                break;
                                            case 1:
                                                CenterText("Digite o número do pedido recebido: ");
                                                scanf("%d", &opcao);
                                                retorno = buscaItemPrato(auxC.pedidos_entregues,opcao,&auxP);
                                                if(retorno==0){
                                                    retorno = removerPrato(auxC.pedidos_entregues,auxP);
                                                    if(retorno==0){
                                                        opcao = 0;
                                                        system("cls");
                                                        CenterText("Confirmação realizada com sucesso!\n");
                                                    }
                                                    else{
                                                        opcao = 0;
                                                        system("cls");
                                                        CenterText("ERRO: não foi possível realizar a confirmação!\n");
                                                    }
                                                }
                                                else{
                                                    opcao = 1;
                                                    system("cls");
                                                    CenterText("ERRO: prato inexistente!\n");
                                                }
                                                break;
                                            default:
                                                opcao = 1;
                                                system("cls");
                                                CenterText("ERRO: opção inválida!\n");
                                            }
                                        }

                                        CenterText("Pressione qualquer tecla para voltar: ");
                                        fflush(stdin);
                                        getc(stdin);
                                        system("cls");
                                        break;

                                    case 5:

                                        CenterText("================== ALTERAÇÃO DE CADASTRO ==================\n\n");

                                        do{
                                            CenterText("Nome atual: "); printf("%s\n", auxC.nome);
                                            CenterText("Deseja alterar seu nome de usuário?\n\n");
                                            CenterText("1. Sim\n");
                                            CenterText("0. Não\n");
                                            CenterText("Opção escolhida: ");
                                            scanf("%d",&opcao);

                                            system("cls");
                                            switch(opcao){
                                            case 1:
                                                CenterText("\nDigite seu novo nome de usuário: ");
                                                fflush(stdin);
                                                fgets(auxC.nome,30,stdin);
                                                auxC.nome[strcspn(auxC.nome,"\n")]='\0';
                                                break;
                                            case 0:
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("Opção inválida, tente novamente!\n");
                                            }

                                        }while((opcao!=1)&&(opcao!=0));

                                        do{
                                            CenterText("E-mail atual: "); printf("%s\n", auxC.email);
                                            CenterText("Deseja alterar seu e-mail?\n\n");
                                            CenterText("1. Sim\n");
                                            CenterText("0. Não\n");
                                            CenterText("Opção escolhida: ");
                                            scanf("%d",&opcao);

                                            system("cls");
                                            switch(opcao){
                                            case 1:
                                                CenterText("\nDigite seu novo e-mail: ");
                                                fflush(stdin);
                                                fgets(auxC.email,50,stdin);
                                                auxC.email[strcspn(auxC.email,"\n")]='\0';
                                                retorno = confereEmail(auxC.email);
                                                if(retorno){
                                                    system("cls");
                                                    CenterText("E-mail inválido, digite novamente!\n");
                                                    opcao = -1;
                                                }
                                                else if(procuraEmailCliente(lc,auxC.email)==0){
                                                    system("cls");
                                                    CenterText("E-mail já cadastrado! Tente novamente.\n");
                                                }
                                                break;
                                            case 0:
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("Opção inválida, tente novamente!\n");
                                            }
                                        }while((opcao!=1)&&(opcao!=0));

                                        do{
                                            CenterText("Deseja alterar sua senha?\n\n");
                                            CenterText("1. Sim\n");
                                            CenterText("0. Não\n");
                                            CenterText("Opção escolhida: ");
                                            scanf("%d",&opcao);

                                            system("cls");
                                            switch(opcao){
                                            case 1:
                                                CenterText("Digite sua senha atual: ");
                                                escondeSenha(aux);
                                                aux[strcspn(aux,"\n")]='\0';
                                                if(strcmp(aux,auxC.senha)!=0){
                                                    system("cls");
                                                    CenterText("Senha incorreta!\n");
                                                    break;
                                                }
                                                CenterText("\nDigite sua nova senha (min. 8 caracteres): ");
                                                escondeSenha(auxC.senha);
                                                auxC.senha[strcspn(auxC.senha,"\n")]='\0';
                                                retorno = confereSenha(auxC.senha);
                                                if(retorno){
                                                    system("cls");
                                                    CenterText("A senha deve conter pelo menos um caratere maiúsculo, um número e um caractere especial! Digite novamente.\n\n");
                                                    opcao = -1;
                                                }
                                                break;
                                            case 0:
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("Opção inválida, tente novamente!");
                                            }
                                        }while((opcao!=1)&&(opcao!=0));

                                        retorno = 1;
                                        ListaP *c = auxC.carrinho;
                                        ListaP *pe = auxC.pedidos_entregues;
                                        ListaP *pr = auxC.pedidos_realizados;
                                        if(removerCliente(lc,auxC)==0){
                                                retorno = inserirCliente(lc,auxC);
                                                auxC.carrinho = c;
                                                auxC.pedidos_entregues = pe;
                                                auxC.pedidos_realizados = pr;
                                        }

                                        if(retorno){
                                            system("cls");
                                            CenterText("Erro ao alterar!\n");
                                        }
                                        else{
                                            system("cls");
                                            CenterText("Dados alterados com sucesso!\n");
                                        }

                                        break;

                                    case 6:
                                        CenterText("Deseja mesmo excluir a sua conta permanentemente?\n");
                                        CenterText("1 - Sim\n");
                                        CenterText("0 - Não\n");

                                        CenterText("Digite a sua opção: ");
                                        scanf("%d", &opcao);

                                        while(opcao){
                                            CenterText("Digite sua senha para confirmar: ");
                                            escondeSenha(aux);
                                            aux[strcspn(aux,"\n")]='\0';
                                            if(strcmp(aux,auxC.senha)==0){
                                                retorno = removerCliente(lc, auxC);
                                                if(retorno){
                                                    system("cls");
                                                    CenterText("ERRO: não foi possível remover o cliente!\n");
                                                }
                                                else{
                                                    opcao = 0;
                                                    menu_cliente = 0;
                                                    system("cls");
                                                    CenterText("Conta excluida com sucesso!\n");
                                                }
                                            }
                                            else{
                                                system("cls");
                                                CenterText("Senha inválida! Tente novamente. \n");
                                            }
                                        }

                                        break;

                                    default:
                                        CenterText("Opcao invalida... Tente novamente.\n");
                                }
                            } while(menu_cliente);

                            break;

                        case 2:

                            CenterText("================== DADOS DE CADASTRO ==================\n\n");
                            CenterText("Nome: ");
                            fflush(stdin);
                            fgets(auxC.nome,29,stdin);
                            auxC.nome[strcspn(auxC.nome,"\n")]='\0';
                            do{
                                CenterText("CPF (111.111.111-11): ");
                                fflush(stdin);
                                fgets(auxC.cpf,15,stdin);
                                retorno = confereCPF(auxC.cpf);
                                if(retorno){
                                    CenterText("CPF inválido! Digite novamente.\n\n");
                                }
                                else if(procuraItemCliente(lc,auxC.cpf)==0){
                                    retorno = 1;
                                    CenterText("CPF já cadastrado! Digite novamente.\n\n");
                                }
                            }while(retorno);

                            do{
                                CenterText("E-mail: ");
                                fflush(stdin);
                                fgets(auxC.email,50,stdin);
                                retorno = confereEmail(auxC.email);
                                auxC.email[strcspn(auxC.email,"\n")]='\0';
                                if(retorno){
                                    CenterText("E-mail inválido! Digite novamente.\n\n");
                                }
                                else if(procuraEmailCliente(lc,auxC.email)==0){
                                    retorno = 1;
                                    CenterText("E-mail já cadastrado! Digite novamente.\n\n");
                                }
                            }while(retorno);

                            do{
                                CenterText("Senha (min. 8 caracteres): ");
                                escondeSenha(auxC.senha);
                                auxC.senha[strcspn(auxC.senha,"\n")]='\0';
                                retorno = confereSenha(auxC.senha);
                                if(retorno){
                                    CenterText("A senha deve conter pelo menos um caratere maiúsculo, um número e um caractere especial! Digite novamente.\n\n");
                                }
                            }while(retorno);

                            retorno = inserirCliente(lc, auxC);

                            system("cls");
                            if(retorno==0){
                                CenterText("Cliente cadastrado com sucesso!\n\n");
                            }
                            else{
                                CenterText("Erro ao cadastrar!\n\n");
                            }
                        break;

                        default:
                            CenterText("Opcao invalida... Tente novamente.\n");
                    }
                } while(menu_cliente_inicio);

                break;

            case 2:
                do
                {
                    CenterText("================== MENU RESTAURANTE ==================\n");
                    CenterText("1.Login.\n");
                    CenterText("2.Cadastro.\n");
                    CenterText("0.Sair.\n");

                    CenterText("Digite sua opcao:");
                    scanf("%d",&menu_restaurante_inicio);

                    system("cls");
                    switch(menu_restaurante_inicio)
                    {
                        case 0: break;

                        case 1:
                            do{
                                CenterText("E-mail: ");
                                fflush(stdin);
                                fgets(auxR.email,50,stdin);
                                auxR.email[strcspn(auxR.email,"\n")]='\0';
                                retorno = confereEmail(auxR.email);
                                if(retorno){
                                    CenterText("E-mail inválido! Digite novamente.\n\n");
                                }
                                else if(procuraEmailRestaurante(lr,auxR.email)!=0){
                                    retorno = 1;
                                    CenterText("E-mail não cadastrado! Digite novamente.\n\n");
                                }
                            }while(retorno);
                            buscaItemRestaurante(lr,auxR.email,&auxR);
                            do{
                                CenterText("Senha: ");
                                escondeSenha(aux);
                                aux[strcspn(aux,"\n")]='\0';
                                retorno = confereSenha(aux);
                                if(retorno){
                                    CenterText("A senha deve conter pelo menos um caratere maiúsculo, um número e um caractere especial! Digite novamente.\n\n");
                                }
                                else if(strcmp(aux, auxR.senha)!=0){
                                    CenterText("Senha incorreta! Digite novamente!\n");
                                    retorno = 1;
                                }
                            }while(retorno);

                            system("cls");
                            do
                            {
                                CenterText("Bem vindo, "); printf("%s\n", auxR.nome_restaurante);
                                CenterText("1.Ver pratos.\n");
                                CenterText("2.Ver pedidos.\n");
                                CenterText("3.Cadastrar prato.\n");
                                CenterText("4.Alterar prato.\n");
                                CenterText("5.Excluir prato.\n");
                                CenterText("6.Alterar dados do restaurante.\n");
                                CenterText("7.Excluir conta.\n");
                                CenterText("0.Sair.\n");

                                CenterText("Digite sua opcao:");
                                scanf("%d",&menu_restaurante);

                                system("cls");
                                switch(menu_restaurante)
                                {
                                    case 0: break;

                                    case 1:
                                        CenterText("================== CARDÁPIO ==================\n");
                                        mostrarPratos(auxR.cardapio);
                                        CenterText("Pressione qualquer tecla para voltar: ");
                                        fflush(stdin);
                                        fgetc(stdin);
                                        system("cls");
                                        break;

                                    case 2:
                                        do{
                                            CenterText("================== PEDIDOS ==================\n");
                                            if(tamanho(auxR.pedidos)!=0){
                                                mostrarPedidos(auxR.pedidos);
                                                CenterText("\nDeseja entregar o primeiro pedido?\n");
                                                CenterText("1 - Sim\n");
                                                CenterText("0 - Não\n");
                                                scanf("%d", &opcao);
                                                if(opcao){
                                                    system("cls");
                                                    retorno = removerPedido(auxR.pedidos, &auxC, &auxP);
                                                    removerPrato(auxC.pedidos_realizados, auxP);
                                                    inserirPrato(auxC.pedidos_entregues, auxP);
                                                    if(retorno){
                                                        opcao = 1;
                                                        CenterText("ERRO: não foi possível entregar o pedido!\n");
                                                    }
                                                    else{
                                                        opcao = 0;
                                                        CenterText("Pedido entregue!\n");
                                                    }

                                                }
                                            }
                                            CenterText("\n\nPressione qualquer tecla para sair: ");
                                            fflush(stdin);
                                            getc(stdin);
                                            system("cls");
                                        }while(opcao);
                                        break;

                                    case 3:
                                        CenterText("================== DADOS DE CADASTRO ==================\n\n");
                                        CenterText("Nome: ");
                                        fflush(stdin);
                                        fgets(auxP.nome,29,stdin);
                                        auxP.nome[strcspn(auxP.nome,"\n")]='\0';

                                        CenterText("Preço: R$ ");
                                        scanf("%f", &auxP.preco);
                                        CenterText("Ingredientes (Ex. Arroz, Feijão, Carne.): ");
                                        fflush(stdin);
                                        fgets(auxP.ingredientes,449,stdin);
                                        auxP.ingredientes[strcspn(auxP.ingredientes,"\n")]='\0';
                                        auxP.codigo = geraCodigo(lr);
                                        auxP.cod_restaurante = auxR.codigo;

                                        retorno = inserirPrato(auxR.cardapio, auxP);
                                        if(retorno){
                                            system("cls");
                                            CenterText("ERRO: não foi possível inserir o prato!\n");
                                        }
                                        else{
                                            system("cls");
                                            CenterText("Prato inserido com sucesso!\n");
                                        }
                                        break;

                                    case 4:
                                        CenterText("================== ALTERAÇÃO DE PRATO ==================\n\n");

                                        CenterText("Digite o código do prato: ");
                                        scanf("%d", &codigo);

                                        retorno = buscaItemPrato(auxR.cardapio, codigo, &auxP);
                                        if(retorno){
                                            CenterText("Código inválido!\n");
                                            break;
                                        }

                                        do{
                                            CenterText("Nome atual: "); printf("%s\n", auxP.nome);
                                            CenterText("Deseja alterar o nome do prato?\n\n");
                                            CenterText("1. Sim\n");
                                            CenterText("0. Não\n");
                                            CenterText("Opção escolhida: ");
                                            scanf("%d",&opcao);

                                            system("cls");
                                            switch(opcao){
                                            case 1:
                                                CenterText("\nDigite o novo nome: ");
                                                fflush(stdin);
                                                fgets(auxP.nome,30,stdin);
                                                auxP.nome[strcspn(auxP.nome,"\n")]='\0';
                                                break;
                                            case 0:
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("Opção inválida, tente novamente!\n");
                                            }
                                        }while((opcao!=1)&&(opcao!=0));

                                        do{
                                            CenterText("Preço atual: ");printf("%.2f\n", auxP.preco);
                                            CenterText("Deseja alterar o preço do prato?\n\n");
                                            CenterText("1. Sim\n");
                                            CenterText("0. Não\n");
                                            CenterText("Opção escolhida: ");
                                            scanf("%d",&opcao);

                                            system("cls");
                                            switch(opcao){
                                            case 1:
                                                CenterText("\nDigite o novo preço: ");
                                                scanf("%f", &auxP.preco);
                                                break;
                                            case 0:
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("Opção inválida, tente novamente!\n");
                                            }
                                        }while((opcao!=1)&&(opcao!=0));

                                        do{
                                            CenterText("Ingredientes atuais: ");printf("%s\n",auxP.ingredientes);
                                            CenterText("Deseja alterar os ingredientes do prato?\n\n");
                                            CenterText("1. Sim\n");
                                            CenterText("0. Não\n");
                                            CenterText("Opção escolhida: ");
                                            scanf("%d",&opcao);

                                            system("cls");
                                            switch(opcao){
                                            case 1:
                                                CenterText("\nDigite os novos ingredientes: ");
                                                fflush(stdin);
                                                fgets(auxP.ingredientes,30,stdin);
                                                auxP.ingredientes[strcspn(auxP.ingredientes,"\n")]='\0';
                                                break;
                                            case 0:
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("Opção inválida, tente novamente!\n");
                                            }

                                        }while((opcao!=1)&&(opcao!=0));

                                        retorno = removerPrato(auxR.cardapio, auxP);
                                        if(retorno){
                                            system("cls");
                                            CenterText("ERRO: não foi possível alterar o prato.\n");
                                        }
                                        else{
                                            retorno = inserirPrato(auxR.cardapio, auxP);
                                            if(retorno){
                                                system("cls");
                                                CenterText("ERRO: não foi possível alterar o prato.\n");
                                            }
                                            else{
                                                system("cls");
                                                CenterText("Prato alterado com sucesso!\n");
                                            }
                                        }

                                        break;

                                    case 5:
                                        CenterText("Digite o código do prato: ");
                                        scanf("%d", &codigo);

                                        retorno = buscaItemPrato(auxR.cardapio, codigo, &auxP);
                                        if(retorno){
                                            CenterText("ERRO: código inválido!\n");
                                            break;
                                        }

                                        CenterText("Deseja mesmo excluir o prato permanentemente?\n");
                                        CenterText("1 - Sim\n");
                                        CenterText("0 - Não\n");

                                        CenterText("Digite a sua opção: ");
                                        scanf("%d", &opcao);

                                        while(opcao){
                                            retorno = removerPrato(auxR.cardapio, auxP);
                                            if(retorno){
                                                system("cls");
                                                CenterText("ERRO: não foi possível remover o prato!\n");
                                            }
                                            else{
                                                opcao = 0;
                                                system("cls");
                                                CenterText("prato excluido com sucesso!\n");
                                            }
                                        }

                                        break;

                                    case 6:
                                        CenterText("================== ALTERAÇÃO DE CADASTRO ==================\n\n");

                                        do{
                                            CenterText("Nome atual:");printf(" %s\n",auxR.nome_proprietario);
                                            CenterText("Deseja alterar seu nome de usuário?\n\n");
                                            CenterText("1. Sim\n");
                                            CenterText("0. Não\n");
                                            CenterText("Opção escolhida: ");
                                            scanf("%d",&opcao);

                                            system("cls");
                                            switch(opcao){
                                            case 1:
                                                CenterText("\nDigite seu novo nome de usuário: ");
                                                fflush(stdin);
                                                fgets(auxR.nome_proprietario,30,stdin);
                                                auxR.nome_proprietario[strcspn(auxR.nome_proprietario,"\n")]='\0';
                                                break;
                                            case 0:
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("Opção inválida, tente novamente!\n");
                                            }
                                        }while((opcao!=1)&&(opcao!=0));

                                        do{
                                            CenterText("Nome do estabelecimento atual: ");printf("%s\n", auxR.nome_restaurante);
                                            CenterText("Deseja alterar o nome do estabelecimento?\n\n");
                                            CenterText("1. Sim\n");
                                            CenterText("0. Não\n");
                                            CenterText("Opção escolhida: ");
                                            scanf("%d",&opcao);

                                            system("cls");
                                            switch(opcao){
                                            case 1:
                                                CenterText("\nDigite seu novo nome de usuário: ");
                                                fflush(stdin);
                                                fgets(auxR.nome_restaurante,30,stdin);
                                                auxR.nome_restaurante[strcspn(auxR.nome_restaurante,"\n")]='\0';
                                                break;
                                            case 0:
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("Opção inválida, tente novamente!\n");
                                            }
                                        }while((opcao!=1)&&(opcao!=0));

                                        do{
                                            CenterText("E-mail atual "); printf(" %s\n", auxR.email);
                                            CenterText("Deseja alterar seu e-mail?\n\n");
                                            CenterText("1. Sim\n");
                                            CenterText("0. Não\n");
                                            CenterText("Opção escolhida: ");
                                            scanf("%d",&opcao);

                                            system("cls");
                                            switch(opcao){
                                            case 1:
                                                CenterText("\nDigite seu novo e-mail: ");
                                                fflush(stdin);
                                                fgets(aux,50,stdin);
                                                aux[strcspn(aux,"\n")]='\0';
                                                retorno = confereEmail(aux);
                                                if(retorno){
                                                    system("cls");
                                                    CenterText("E-mail inválido, digite novamente!\n");
                                                    opcao = -1;
                                                }
                                                else if(procuraEmailRestaurante(lr,aux)==0){
                                                    system("cls");
                                                    CenterText("E-mail já cadastrado! Tente novamente.\n");
                                                }
                                                else{
                                                    opcao = 1;
                                                    strcpy(auxR.email,aux);
                                                }
                                                break;
                                            case 0:
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("Opção inválida, tente novamente!\n");
                                            }
                                        }while((opcao!=1)&&(opcao!=0));

                                        do{
                                            CenterText("Deseja alterar sua senha?\n\n");
                                            CenterText("1. Sim\n");
                                            CenterText("0. Não\n");
                                            CenterText("Opção escolhida: ");
                                            scanf("%d",&opcao);

                                            system("cls");
                                            switch(opcao){
                                            case 1:
                                                CenterText("Digite sua senha atual: ");
                                                escondeSenha(aux);
                                                aux[strcspn(aux,"\n")]='\0';
                                                if(strcmp(aux,auxR.senha)!=0){
                                                    system("cls");
                                                    CenterText("Senha incorreta!\n");
                                                    break;
                                                }
                                                CenterText("\nDigite sua nova senha (min. 8 caracteres): ");
                                                escondeSenha(aux);
                                                aux[strcspn(aux,"\n")]='\0';
                                                retorno = confereSenha(aux);
                                                if(retorno){
                                                    system("cls");
                                                    CenterText("A senha deve conter pelo menos um caratere maiúsculo, um número e um caractere especial! Digite novamente.\n\n");
                                                    opcao = -1;
                                                }
                                                else{
                                                    strcpy(auxR.senha,aux);
                                                }
                                                break;
                                            case 0:
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("Opção inválida, tente novamente!");
                                            }
                                        }while((opcao!=1)&&(opcao!=0));

                                        do{
                                            CenterText("Categoria atual: ");printf("%s\n", auxR.categoria);
                                            CenterText("Deseja alterar sua categoria?\n\n");
                                            CenterText("1. Sim\n");
                                            CenterText("0. Não\n");
                                            CenterText("Opção escolhida: ");
                                            scanf("%d",&opcao);

                                            system("cls");
                                            switch(opcao){
                                            case 1:
                                                mostraCategoria(auxR.categoria);
                                                break;
                                            case 0:
                                                break;
                                            default:
                                                system("cls");
                                                CenterText("Opção inválida, tente novamente!\n");
                                            }
                                        }while((opcao!=1)&&(opcao!=0));

                                        FilaPedidos *f = auxR.pedidos;
                                        ListaP *lp = auxR.cardapio;
                                        retorno = 1;
                                        if(removerRestaurante(lr,auxR)==0){
                                                inserirRestaurante(lr,auxR);
                                                auxR.pedidos = f;
                                                auxR.cardapio = lp;
                                        }

                                        if(retorno){
                                            system("cls");
                                            CenterText("Erro ao alterar!\n");
                                        }
                                        else{
                                            system("cls");
                                            CenterText("Dados alterados com sucesso!\n");
                                        }

                                        break;

                                    case 7:
                                        CenterText("Deseja mesmo excluir a sua conta permanentemente?\n");
                                        CenterText("1 - Sim\n");
                                        CenterText("0 - Não\n");

                                        CenterText("Digite a sua opção: ");
                                        scanf("%d", &opcao);

                                        while(opcao){
                                            CenterText("Digite sua senha para confirmar: ");
                                            escondeSenha(aux);
                                            aux[strcspn(aux,"\n")]='\0';
                                            if(strcmp(aux,auxR.senha)==0){
                                                retorno = removerRestaurante(lr, auxR);
                                                if(retorno){
                                                    system("cls");
                                                    CenterText("ERRO: não foi possível remover o restaurante!\n");
                                                }
                                                else{
                                                    opcao = 0;
                                                    menu_restaurante = 0;
                                                    system("cls");
                                                    CenterText("Conta excluida com sucesso!\n");
                                                }
                                            }
                                            else{
                                                system("cls");
                                                CenterText("Senha inválida! Tente novamente. \n");
                                            }
                                        }

                                        break;

                                    default:
                                        CenterText("Opcao invalida...Tente novamente.\n");
                                }
                            } while(menu_restaurante);

                            break;

                        case 2:

                            CenterText("================== DADOS DE CADASTRO ==================\n\n");
                            CenterText("Nome: ");
                            fflush(stdin);
                            fgets(auxR.nome_proprietario,29,stdin);
                            auxR.nome_proprietario[strcspn(auxR.nome_proprietario,"\n")]='\0';
                            CenterText("Nome do Restaurante: ");
                            fflush(stdin);
                            fgets(auxR.nome_restaurante,29,stdin);
                            auxR.nome_restaurante[strcspn(auxR.nome_restaurante,"\n")]='\0';
                            do{
                                CenterText("CNPJ (XX.XXX.XXX/0001-XX): ");
                                fflush(stdin);
                                fgets(auxR.cnpj,18,stdin);
                                retorno = confereCNPJ(auxR.cnpj);
                                if(retorno){
                                    CenterText("CNPJ inválido! Digite novamente.\n\n");
                                }
                                else if(procuraItemRestaurante(lr,auxR.cnpj)==0){
                                    retorno = 1;
                                    CenterText("CNPJ já cadastrado! Digite novamente.\n\n");
                                }
                            }while(retorno);

                            do{
                                CenterText("E-mail: ");
                                fflush(stdin);
                                fgets(auxR.email,50,stdin);
                                retorno = confereEmail(auxR.email);
                                auxR.email[strcspn(auxR.email,"\n")]='\0';
                                if(retorno){
                                    CenterText("E-mail inválido! Digite novamente.\n\n");
                                }
                                else if(procuraEmailRestaurante(lr,auxR.email)==0){
                                    retorno = 1;
                                    CenterText("E-mail já cadastrado! Digite novamente.\n\n");
                                }
                            }while(retorno);

                            do{
                                CenterText("Senha (min. 8 caracteres): ");
                                fflush(stdin);
                                escondeSenha(auxR.senha);
                                retorno = confereSenha(auxR.senha);
                                if(retorno){
                                    CenterText("A senha deve conter pelo menos um caratere maiúsculo, um número e um caractere especial! Digite novamente.\n\n");
                                }
                            }while(retorno);

                            mostraCategoria(categoria);
                            strcpy(auxR.categoria,categoria);

                            retorno = inserirRestaurante(lr, auxR);

                            system("cls");
                            if(retorno==0){
                                CenterText("Restaurante cadastrado com sucesso!\n\n");
                            }
                            else{
                                CenterText("Erro ao cadastrar!\n\n");
                            }
                            break;

                        default:
                            CenterText("Opcao invalida... Tente novamente.\n");
                    }
                } while(menu_restaurante_inicio);

                break;

                    default:
                        CenterText("Opcao invalida... Tente novamente.\n");
        }
    } while(menu_inicial);

    return 0;
}

int confereCPF(char *cpf){
    int i, tam=0;
    for(i=0; cpf[i]!='\0'; i++){
        if((i!=3 && i!=7 && i!=11) && (cpf[i]<'0' && cpf[i]>'9')) return -1;
        tam++;
    }
    if(cpf[11]!='-') return -1;
    if(cpf[3]!='.' || cpf[7]!='.') return -1;
    if(tam<14) return -1;
    return 0;
}

int confereEmail(char *email){
    int i, arroba=0, ponto = 0;
    for(i=0; email[i]!='\0'; i++){
        if(email[i]=='@') arroba++;
        else if(email[i]=='.' && arroba==1) ponto++;
    }
    if(arroba!=1) return -1;
    if(ponto!=1) return -1;

    return 0;
}

int confereSenha(char *senha){
    int i, maiuscula=0, numero = 0, especial = 0, tam=0;
    for(i=0; senha[i]!='\0'; i++){
        if(senha[i]>='A' && senha[i]<='Z') maiuscula++;
        else if(senha[i]>='1' && senha[i]<='9') numero++;
        else if((senha[i]>='!' && senha[i]<='@')||(senha[i]>=':' && senha[i]<='@')|| senha[i]=='_') especial++;
        tam++;
    }
    if(maiuscula && especial && numero &&(tam>=8)) return 0;
    return -1;
}

int confereCNPJ(char *cnpj){
    int i, tam=0;
    for(i=0; cnpj[i]!='\0'; i++){
        if((i!=2 && i!=6 && i<10 && i>15) && (cnpj[i]<'0' && cnpj[i]>'9')) return -1;
        tam++;
    }

    if(tam!=17) return -1;
    if(cnpj[15]!='-') return -1;
    if(cnpj[2]!='.' || cnpj[6]!='.') return -1;
    if(cnpj[10]!='/') return -1;
    if(cnpj[11]!='0' || cnpj[12]!='0' || cnpj[13]!='0' || (cnpj[14]!='1' && cnpj[14]!='2')) return -1;


    return 0;
}

void mostraCategoria(char *categoria){
    int op;

    do{
        printf("\n");
        CenterText("Escolha a categoria: \n");
        CenterText("1 - Bebidas\n");
        CenterText("2 - Cafeteria\n");
        CenterText("3 - Saudável e fitness\n");
        CenterText("4 - Fast food\n");
        CenterText("5 - Doces e bolos\n");
        CenterText("6 - Padaria\n");
        CenterText("7 - Comida japonesa\n");
        CenterText("8 - Frutos do mar\n");
        CenterText("9 - Massas\n");
        CenterText("10 - Pizzaria\n");
        CenterText("11 - Pastelaria\n");
        CenterText("12 - Hamburgueria\n");
        CenterText("13 - Churrascaria\n");
        CenterText("14 - Salgados\n");
        CenterText("15 - Sorveteria\n");
        CenterText("16 - Vegetariano e vegano\n");
        CenterText("17 - Sem categoria\n\n");

        CenterText("opção: ");
        scanf("%d", &op);

        switch(op){
        case 1:
            strcpy(categoria,"Bebidas");
            break;
        case 2:
            strcpy(categoria,"Cafeteria");
            break;
        case 3:
            strcpy(categoria,"Saudável e fitness");
            break;
        case 4:
            strcpy(categoria,"Fast food");
            break;
        case 5:
            strcpy(categoria,"Doces e bolos");
            break;
        case 6:
            strcpy(categoria,"Padaria");
            break;
        case 7:
            strcpy(categoria,"Comida japonesa");
            break;
        case 8:
            strcpy(categoria,"Frutos do mar");
            break;
        case 9:
            strcpy(categoria,"Massas");
            break;
        case 10:
            strcpy(categoria,"Pizzaria");
            break;
        case 11:
            strcpy(categoria,"Pastelaria");
            break;
        case 12:
            strcpy(categoria,"Hamburgueria");
            break;
        case 13:
            strcpy(categoria,"Churrascaria");
            break;
        case 14:
            strcpy(categoria,"Salgados");
            break;
        case 15:
            strcpy(categoria,"Sorveteria");
            break;
        case 16:
            strcpy(categoria,"Vegetariano e vegano");
            break;
        case 17:
            strcpy(categoria,"Sem categoria");
            break;
        default:
            system("cls");
            CenterText("Opção inválida! Digite novamente.\n\n");
        }
    }while(op<1 && op>16);

}

void escondeSenha (char *senha)
{
    int i = 0;
    char ch, senha_ast[15];

    while (i < 14)
    {
        ch = getch();
        if (ch == ' ') {
            --i;
        } else if (ch == '\b') {
            printf("\b \b");
            i -= 2;
        } else if (ch == '\r')
            break;
        else {
            senha_ast[i] = ch;
            printf("*");
        }
        ++i;
    }

    senha_ast[i] = '\0';
    strcpy(senha, senha_ast);
}

void CenterText(const char *text) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(console, &consoleInfo);
    int textLength = strlen(text);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left;
    int posX = (consoleWidth - textLength) / 2;
    int posY = consoleInfo.dwCursorPosition.Y;
    COORD newPos;
    newPos.X = posX;
    newPos.Y = posY;
    SetConsoleCursorPosition(console, newPos);
    printf("%s", text);
}


