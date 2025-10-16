#include <stdio.h>

int main() {
    float vel_ms, vel_kmh, vel_convertida;
    printf("Digite a velocidade em m/s:\n");
    scanf("%f", &vel_ms);
    vel_convertida = vel_ms * 3.6;
    printf("A velocidade que você digitou convertida para KM/h é:%.2f\n",vel_convertida);

    return 0;
}