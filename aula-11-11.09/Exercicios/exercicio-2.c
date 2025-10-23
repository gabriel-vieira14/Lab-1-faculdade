#include <stdio.h>

int main() {
    int soma = 0, intervalo, cont;
    for(cont = 100; cont <= 200; cont++) {
        if(cont % 13 != 0) {
            soma = soma + cont;
        } 
    }
    printf("O resultado da soma dos números que não são múltiplos de 13 é:%d", soma);
}