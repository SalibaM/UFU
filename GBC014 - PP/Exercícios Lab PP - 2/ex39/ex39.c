#include <stdio.h>

int main()
{

    int temposerv;
    float salario, reajuste, salariof;

    printf("Digite o seu salario atual:");
    scanf("%f", &salario);

    printf("Digite o seu tempo de servico em anos:");
    scanf("%d", &temposerv);

    if ((temposerv == 0))
    {
        printf("Voce nao tem direito.");
    }
    else
    {

        if ((salario <= 500) && (temposerv < 1))
        {
            reajuste = (0.25 * salario);
            salariof = salario + reajuste;
            printf("O salario final sera:%f", salariof);
        }
        else
        {
            if ((salario <= 500) && ((temposerv >= 1 && temposerv <= 3)))
            {
                reajuste = (0.25 * salario);
                salariof = salario + reajuste + 100;
                printf("O salario final sera:%f", salariof);
            }
            else
            {
                if ((salario <= 500) && ((temposerv >= 4 && temposerv <= 6)))
                {
                    reajuste = (0.25 * salario);
                    salariof = salario + reajuste + 200;
                    printf("O salario final sera:%f", salariof);
                }
                else
                {
                    if ((salario <= 500) && ((temposerv >= 7 && temposerv <= 10)))
                    {
                        reajuste = (0.25 * salario);
                        salariof = salario + reajuste + 300;
                        printf("O salario final sera:%f", salariof);
                    }
                    else
                    {
                        if ((salario <= 500) && (temposerv >= 10))
                        {
                            salariof = salario + 500;
                            printf("O salario final sera:%f", salariof);
                        }
                        else
                        {
                            if ((salario <= 1000 && salario > 500) && (temposerv < 1))
                            {
                                reajuste = (0.20 * salario);
                                salariof = salario + reajuste;
                                printf("O salario final sera:%f", salariof);
                            }
                            else
                            {
                                if ((salario <= 1000 && salario > 500) && ((temposerv >= 1 && temposerv <= 3)))
                                {
                                    reajuste = (0.20 * salario);
                                    salariof = salario + reajuste + 100;
                                    printf("O salario final sera:%f", salariof);
                                }
                                else
                                {
                                    if ((salario <= 1000 && salario > 500) && ((temposerv >= 4 && temposerv <= 6)))
                                    {
                                        reajuste = (0.20 * salario);
                                        salariof = salario + reajuste + 200;
                                        printf("O salario final sera:%f", salariof);
                                    }
                                    else
                                    {
                                        if ((salario <= 1000 && salario > 500) && ((temposerv >= 7 && temposerv <= 10)))
                                        {
                                            reajuste = (0.20 * salario);
                                            salariof = salario + reajuste + 300;
                                            printf("O salario final sera:%f", salariof);
                                        }
                                        else
                                        {
                                            if ((salario <= 1000 && salario > 500) && (temposerv >= 10))
                                            {
                                                salariof = salario + 500;
                                                printf("O salario final sera:%f", salariof);
                                            }
                                            else
                                            {
                                                if ((salario <= 1500 && salario > 1000) && (temposerv < 1))
                                                {
                                                    reajuste = (0.15 * salario);
                                                    salariof = salario + reajuste;
                                                    printf("O salario final sera:%f", salariof);
                                                }
                                                else
                                                {
                                                    if ((salario <= 1500 && salario > 1000) && ((temposerv >= 1 && temposerv <= 3)))
                                                    {
                                                        reajuste = (0.15 * salario);
                                                        salariof = salario + reajuste + 100;
                                                        printf("O salario final sera:%f", salariof);
                                                    }
                                                    else
                                                    {
                                                        if ((salario <= 1500 && salario > 1000) && ((temposerv >= 4 && temposerv <= 6)))
                                                        {
                                                            reajuste = (0.15 * salario);
                                                            salariof = salario + reajuste + 200;
                                                            printf("O salario final sera:%f", salariof);
                                                        }
                                                        else
                                                        {
                                                            if ((salario <= 1500 && salario > 1000) && ((temposerv >= 7 && temposerv <= 10)))
                                                            {
                                                                reajuste = (0.15 * salario);
                                                                salariof = salario + reajuste + 300;
                                                                printf("O salario final sera:%f", salariof);
                                                            }
                                                            else
                                                            {
                                                                if ((salario <= 1500 && salario > 1000) && (temposerv >= 10))
                                                                {
                                                                    salariof = salario + 500;
                                                                    printf("O salario final sera:%f", salariof);
                                                                }
                                                                else
                                                                {
                                                                    if ((salario <= 2000 && salario > 1500) && (temposerv < 1))
                                                                    {
                                                                        reajuste = (0.10 * salario);
                                                                        salariof = salario + reajuste;
                                                                        printf("O salario final sera:%f", salariof);
                                                                    }
                                                                    else
                                                                    {
                                                                        if ((salario <= 2000 && salario > 1500) && ((temposerv >= 1 && temposerv <= 3)))
                                                                        {
                                                                            reajuste = (0.10 * salario);
                                                                            salariof = salario + reajuste + 100;
                                                                            printf("O salario final sera:%f", salariof);
                                                                        }
                                                                        else
                                                                        {
                                                                            if ((salario <= 2000 && salario > 1500) && ((temposerv >= 4 && temposerv <= 6)))
                                                                            {
                                                                                reajuste = (0.10 * salario);
                                                                                salariof = salario + reajuste + 200;
                                                                                printf("O salario final sera:%f", salariof);
                                                                            }
                                                                            else
                                                                            {
                                                                                if ((salario <= 2000 && salario > 1500) && ((temposerv >= 7 && temposerv <= 10)))
                                                                                {
                                                                                    reajuste = (0.10 * salario);
                                                                                    salariof = salario + reajuste + 300;
                                                                                    printf("O salario final sera:%f", salariof);
                                                                                }
                                                                                else
                                                                                {
                                                                                    if ((salario <= 2000 && salario > 1500) && (temposerv >= 10))
                                                                                    {
                                                                                        salariof = salario + 500;
                                                                                        printf("O salario final sera:%f", salariof);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((salario > 2000) && (temposerv < 1))
                                                                                        {
                                                                                            reajuste = 0;
                                                                                            salariof = salario + reajuste;
                                                                                            printf("O salario final sera:%f", salariof);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if ((salario > 2000) && ((temposerv >= 1 && temposerv <= 3)))
                                                                                            {
                                                                                                reajuste = 0;
                                                                                                salariof = salario + reajuste + 100;
                                                                                                printf("O salario final sera:%f", salariof);
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if ((salario > 2000) && ((temposerv >= 4 && temposerv <= 6)))
                                                                                                {
                                                                                                    reajuste = 0;
                                                                                                    salariof = salario + reajuste + 200;
                                                                                                    printf("O salario final sera:%f", salariof);
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    if ((salario > 2000) && ((temposerv >= 7 && temposerv <= 10)))
                                                                                                    {
                                                                                                        reajuste = 0;
                                                                                                        salariof = salario + reajuste + 300;
                                                                                                        printf("O salario final sera:%f", salariof);
                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                        if ((salario > 2000) && (temposerv >= 10))
                                                                                                        {
                                                                                                            salariof = salario + 500;
                                                                                                            printf("O salario final sera:%f", salariof);
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            printf("Voce nao tem direito a nenhum aumento...");
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}