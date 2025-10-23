#include <stdio.h>

int main()
{
    int i = 0, numeros = 0;
    int menor_100_1000;
    int media_100_1000;
    while (i < 0)
    {
        printf("Digite um número:\n");
        scanf("%d", &numeros);
        numeros = numeros + numeros;
        i++;
    }
    if (numeros < 100 && numeros > 1000)
    {
        menor_100_1000 = 101;
        printf("%d", menor_100_1000);
    }
}