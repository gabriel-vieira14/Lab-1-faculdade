#include <stdio.h>

int main() {
    float razao,primeiro_termo, decimo_termo;
    printf("Qual a razão da PA?\n");
    scanf("%f", &razao);
    printf("Qual o valor do primeiro termo?\n");
    scanf("%f",&primeiro_termo);

    decimo_termo = primeiro_termo + (10 -1) * razao;
    printf("O decimo termo da PA e: %.2f\n", decimo_termo);
}