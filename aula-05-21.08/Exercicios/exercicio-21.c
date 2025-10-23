#include <stdio.h>

int main()
{
    int n;
    int n_min = 1000;
    int n_max = 9999;
    int unidade, dezena, centena, milhar;
    printf("Digite um número:\n");
    scanf("%d", &n);
    if (n >= n_min && n <= n_max)
    {
        unidade = n % 10;
        dezena = (n / 10) % 10;
        centena = (n / 100) % 10;
        milhar = (n / 1000) % 10;

        printf("unidade = %d dezena = %d centena = %d milhar = %d \n", unidade, dezena, centena, milhar);
    }
}