#include <stdio.h>

int main() {
    float b, h, area;

    printf("Digite o valor da base do triangulo:\n");
    scanf("%f", &b);
    printf("Digite o valor da altura do triangulo:\n");
    scanf("%f", &h);

    area = (b * h) / 2;

    printf("A area do triangulo é:%.2f\n", area);
}