#include <stdio.h>

int e_primo(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
// verifica se e primo
void arranjo(int n)
{
    int primo_1, primo_2;

    for (int i = 2; i < n; i++)
    {
        if (e_primo(i))
        {
            primo_1 = i;
            primo_2 = n - primo_1; // se o primeiro n for primo e o segundo tbm for, vai mostrar os dois e os seguintes
            if (e_primo(primo_2))
            {
                printf("%d +%d\n ", primo_1, primo_2);
            }
        }
    }
}
int main()
{
    int n;
    printf("Digite um numero:\n");
    scanf("%d", &n);
    arranjo(n);
}
// o programa vai imprimir os números primos e o que falta pra chegar no número "n"