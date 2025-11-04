#include <stdio.h>
char inverte_string(char *n)
{

    for (int i = 9; i > 0; i--)
    {
        n[i] = n[i - 1];
        for (int j = 0; j > 9; j++)
        {
            n[j] = n[j + 1];
        }
    }
    printf("Esta é a string invertida: %s", n);
}
int main()
{
    char nome[10];
    scanf("%s", nome);
    inverte_string(nome);
}
