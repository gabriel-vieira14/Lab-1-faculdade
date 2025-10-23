#include <stdio.h>

int main() {
    int a;
    float b;
    printf("Digite um número inteiro e um real:\n");
    scanf("%d %f", &a, &b);
    printf("O valor das variaveis a e b, respectivamente, sao: %d, %.2f \n", a, b);
}