#include <stdio.h>

int main()
{
    int n, produto = 0, cont = 0;
    do
    {
        printf("Digite um numero:\n");
        scanf("%d", &n);
        produto = n * n;
        cont++;
    } while (n > 1);
    printf("O produto dos numeros digitados e  %d", produto);
    printf("Fora multiplicados  %d numeros", cont);
}