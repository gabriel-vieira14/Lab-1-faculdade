#include <stdio.h>
#include <math.h>
int main() {
    float lado1,lado2,lado3, area, s;
    printf("Digite o tamanho em cm do lado 1:\n");
    scanf("%f",&lado1);
    printf("Digite o tamanho em cm do lado 2:\n");
    scanf("%f",&lado2);
    printf("Digite o tamanho em cm do lado 3:\n");
    scanf("%f",&lado3);


    if(((lado1 < (lado2 + lado3)) && lado1 > fabs(lado2 - lado3)) 
    && ((lado2 < (lado1 + lado3)) && lado2 > fabs(lado1 - lado3)) 
    && ((lado3 < (lado2 + lado1)) && lado3 > fabs(lado1 - lado2))) {
        printf("As medidas formam um triângulo!\n");
        s= (lado1 +lado2 + lado3)/2;
        area= sqrt(s * (s- lado1) * (s- lado2) * (s - lado3));
        printf("A área do triângulo é de: %.2f cm\n", area);
    } else {
        printf("As medidas não formam um triângulo\n");
    }
    return 0;
}