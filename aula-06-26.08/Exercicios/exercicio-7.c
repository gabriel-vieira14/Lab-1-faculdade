#include <stdio.h>

int main() {
    float n1,n2, res;
    char op;
    printf("-----------------\n");
    printf("Calculadora de operações básicas\n");
    printf("-----------------\n");
    printf("Digite um número:\n");
    scanf("%f", &n1);
    printf("Digite  outro número:\n");
    scanf("%f", &n2);
    printf("Digite a operação a ser feita: (+, - , * ou / apenas)\n");
    scanf(" %c", &op);
    if(op == '+') {
        res = n1 + n2;
    } else if (op == '-') {
        res = n1 - n2;
    } else if(op == '*') {
        res = n1 * n2;
    } else if(op == '/') {
        res = n1 / n2;
    } else {
        printf("Voce digitou uma operação inválida!Digite apenas uma das quatro operações básicas!");
    }
    printf("O resultado da conta é: %.2f", res);
}