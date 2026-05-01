#include <stdio.h>
#include <math.h>
int main() {
    int primeira_metade, segunda_metade,quadrado_primeira_metade, quadrado_segunda_metade, soma_quadrados;
    printf("Números interessantes: ");
    for (int i = 1000; i <= 9999; i++) {
        primeira_metade = i / 100;
        segunda_metade = i % 100;
        quadrado_primeira_metade = pow(primeira_metade,2);
        quadrado_segunda_metade = pow(segunda_metade, 2);
        soma_quadrados = quadrado_primeira_metade + quadrado_segunda_metade;
        if(i == soma_quadrados) {
            printf("%d ",i);
        }
    }
    printf("\n");
}