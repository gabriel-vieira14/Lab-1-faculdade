#include <stdio.h>

int main() {
    float altura,peso_ideal;
    char sexo;

    printf("---------------\n");
    printf("Calculadora de peso ideal\n");
    printf("---------------\n");
    printf("Digite sua altura:\n");
    scanf("%f",&altura);
    printf("Digite seu sexo:(m=masculino ou F=feminino)");
    scanf(" %c",&sexo);
    if(sexo == 'm') {
        peso_ideal = (72.7 * altura) - 58;
    } else if (sexo == 'f') {
        peso_ideal = (62.1 * altura) - 44.7;
    }
    printf("Seu peso ideal é %.2f", peso_ideal);
}