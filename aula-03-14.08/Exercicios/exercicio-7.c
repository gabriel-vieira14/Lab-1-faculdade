#include <stdio.h>

int main()
{
    int data, dia, mes, ano;
    printf("Digite uma data no formato ddmmaa");
    scanf("%d", &data);
    // 121025
    dia = data / 100000;
    // 121025 / 10000 = 12
    mes = (((data % 100000) / 100) % 100);
    // 121025 % 100000 = 1025
    //  1025 / 100 = 10
    ano = (data % 100);
    printf("O dia e %d, o mes e %d e o ano e %d", dia, mes, ano);
}