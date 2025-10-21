#include <stdio.h>

int main() {
    float m2,hectar;
    printf("Digite um valor em hectar:\n");
    scanf("%f", &hectar);
    m2 = hectar * 10000;
    printf("A área em m² é: %.2f m²\n",m2);
}