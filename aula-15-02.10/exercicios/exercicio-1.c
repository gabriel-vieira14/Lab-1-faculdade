#include <stdio.h>
#define TAM 10
int main()
{
    int vet[10], ocorr = 0, n;

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite um numero?\n");
        scanf("%d", &vet[i]);
    }
    printf("Digite o valor a ser buscado dentro do vetor:\n");
    scanf("%d", &n);
    for (int i = 0; i < TAM; i++)
    {
        if (vet[i] == n)
        {
            ocorr++;
        }
    }
    printf("Número de ocorrencias: %d\n", ocorr);
}