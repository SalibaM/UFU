#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *p = NULL;
    int tamanho, i;

    printf ("\nDigite o tamanho da string desejada: ");
    scanf ("%d", &tamanho);

    p = (char*) calloc(tamanho, sizeof(char));
    if (p == NULL)
    {
        printf("\nErro de falta de memoria.");
        exit (1);
    }
    else
    {
        printf("\nDigite a string: ");
        setbuf(stdin, NULL);
        fgets(p,tamanho,stdin);
    }
    for (i=0; p[i] != '\0'; i++)
    {
        if ((p[i] == 'A') || (p[i] == 'a') || (p[i] == 'E') || (p[i] == 'e') || (p[i] == 'I') || (p[i] == 'i') || (p[i] == 'O') || (p[i] == 'o') || (p[i] == 'U') || (p[i] == 'u'))
        {
            for (int j=i; p[j] != '\0'; j++)
            {
                p[j] = p[j+1];
            }
            i--;
        }
    }
    printf("\n%s", p);

    return 0;
}