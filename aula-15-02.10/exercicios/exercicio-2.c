#include <stdio.h>
#define TAM 5
int main()
{
    float vet_p_ou_n[TAM];
    for (int i = 0; i < TAM; i++)
    {
        printf("Digite um valor a partir de 0:\n");
        scanf("%f", &vet_p_ou_n[i]);
    }
    for (int i = 0; i < TAM; i++)
    {
        if (vet_p_ou_n[i] == 0)
        {
            vet_p_ou_n[i] = -99;
        }
        printf("%.2f", vet_p_ou_n[i]);
    }
}