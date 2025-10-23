#include <stdio.h>

int main() {
    float nota1,nota2,peso1,peso2;
    float media_ponderada;
    printf("CALCULADORA DE MÉDIA PONDERADA EM C\n\n");
    printf("Digite a nota 1:\n");
    scanf("%f", &nota1);
    printf("Digite a nota 2:\n");
    scanf("%f", &nota2);
    printf("Digite a peso 1:\n");
    scanf("%f", &peso1);
    printf("Digite a peso 2:\n");
    scanf("%f", &peso2);
    media_ponderada = (((nota1 * peso1) + (nota2 * peso2)) / (peso1 + peso2)); 
    printf("A media ponderada entre as notas e: %f", media_ponderada);
    return 0;
}