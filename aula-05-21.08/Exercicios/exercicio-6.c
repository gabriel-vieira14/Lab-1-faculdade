#include <stdio.h>

int main() {
    float m2, acres;

    printf("Digite um valor em acres:\n");
    scanf("%f",&acres);
    m2 = acres * 4048.58;
    printf("O valor em acres convertido para m² é igual a:%f\n",m2);

}