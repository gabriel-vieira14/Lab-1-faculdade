#include <stdio.h>

int main() {
    int idade, dias_restantes;
    printf("Qual a sua idade?");
    scanf("%d",&idade);
    dias_restantes = idade * 365;
    printf("Voce tem %d dias restantes.", dias_restantes);
    return 0;
}