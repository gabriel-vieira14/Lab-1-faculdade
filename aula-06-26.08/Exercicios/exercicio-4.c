#include <stdio.h>

int main()
{

    int n;

    printf("Digite um número:\n");
    scanf("%d", &n);

    if (n % 3 == 0 && n % 7 == 0)
    {
        printf("Este número é divisível por 3 e por 7 ao mesmo tempo.\n");
    }
}