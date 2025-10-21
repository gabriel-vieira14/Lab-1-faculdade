#include <stdio.h>

int main() {
    float pol,cent;
    printf("Digite o comprimento em polegadas:\n");
    scanf("%f", &pol);
    cent = pol * 2.54; 
    printf("O comprimento em centimetros e de: %.2f", cent);
    return 0;
}