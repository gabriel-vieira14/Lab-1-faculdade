#include <stdio.h>

int main()
{
    int tam = 3, vet_A[tam], vet_removidos[tam], j = 0;
    for (int i = 0; i <= (tam - 1); i++)
    {
        printf("Digite um número:\n");
        scanf("%d", &vet_A[i]);
    }
    for (int k = 0; k < tam; k++)
    {
        if (vet_A[k] <= 0)
        {
            vet_removidos[j] = vet_A[k];
            j++;
        }
    }
    for (int h = 0; h < tam; h++)
    {
        printf("%d ", vet_A[h]);
    }
    printf("\n");
    for (int q = 0; q < tam; q++)
    {
        printf("%d ", vet_removidos[q]);
    }
}