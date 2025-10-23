#include <stdio.h>

int main()
{
    int n, soma = 0;
    do
    {
        printf("Digite um numero:\n");
        scanf("%d", &n);
        soma = soma + n;
    } while (n > 0);
    printf("A soma dos numeros digitados e de  %d", soma);
}