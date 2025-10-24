#include <stdio.h>

int main()
{
    int assinatura_basica = 7;
    float consumo;
    float preco_11_30 = 1, preco_31_100 = 2, preco_101_mais = 5, vl_conta;

    printf("Digite o consumo da residência:\n");
    scanf("%f", &consumo);
    if (consumo > 100)
    {
        vl_conta = 7 + (20 * preco_11_30) + (70 * preco_31_100) + ((consumo - 100) * preco_101_mais);
    }
    else if (consumo > 30)
    {
        vl_conta = 7 + (20 * preco_11_30) + ((consumo - 30) * preco_31_100);
    }
    else if (consumo > 10)
    {
        vl_conta = 7 + ((consumo - 10) * preco_11_30);
    }
    else
    {
        vl_conta = 7;
    }
    printf("O valor da sua conta de água é de R$ %.2f.", vl_conta);
}
