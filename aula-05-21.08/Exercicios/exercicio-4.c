#include <stdio.h>

int main() {
    float pol,cent;
    printf("Digite o comprimento em centimetros:\n");
    scanf("%f", &cent);
    pol = cent / 2.54; 
    printf("O comprimento em polegadas e de: %.2f", pol);
    return 0;
} 