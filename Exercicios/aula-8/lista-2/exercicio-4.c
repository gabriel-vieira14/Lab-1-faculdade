#include <stdio.h>
int main() {
    int primeira_metade, segunda_metade, soma, quadrado_soma;
    printf("Números interessantes: ");
    for (int i = 1000; i <= 9999; i++) {
        primeira_metade = i / 100;
        segunda_metade = i % 100;
        soma = primeira_metade + segunda_metade;
        quadrado_soma = soma * soma;
        if(i == quadrado_soma) {
            printf("%d ",i);
        }
    }
    printf("\n");
}