#include <stdio.h>

int main() {
    float m2,hectares;
    printf("Digite um valor em m²:\n");
    scanf("%f", &m2);
    hectares = m2 * 0.0001;
    printf("A área em hectares é: %.2f hectares\n",hectares);
}