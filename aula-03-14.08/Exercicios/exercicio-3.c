#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    printf("Digite uma temperatura em graus Celsius");
    scanf("%f", &celsius);
    fahrenheit = celsius * 1.8 +32;
    printf("A temperatura digitada, em Fahrenheit, é: %f", fahrenheit);
    return 0;
}