#include <stdio.h>

int main() {
    int numero,dezena;
    printf("Digite um número de 3 algarismos:\n");
    scanf("%d",&numero);
    dezena = (numero % 100) / 10;
    /*se fosse 325 seria 325 /100 = 3 com resto 25 e depois 25 / 10 = 2*/
    printf("Os algarismo das dezenas e %d", dezena);

}