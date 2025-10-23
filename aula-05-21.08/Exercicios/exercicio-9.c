#include <stdio.h>

int main() {
    float dolar, real, resultado;
    printf("Digite a cotação do dólar de hoje:\n");
    scanf("%f", &dolar);
    printf("Digite um valor em real para ser convertido em dólar:\n");
    scanf("%f", &real);
    resultado = real * dolar;
    printf("O resultado da conversão de real para dólar é de: U$D%.2f\n",resultado);
}