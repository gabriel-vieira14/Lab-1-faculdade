#include <stdio.h>

int main() {
    float m2, acres;

    printf("Digite um valor em m²:\n");
    scanf("%f",&m2);
    acres = m2 * 0.000247;
    printf("O valor em m² convertido para acres é igual a:%f\n",acres);

}