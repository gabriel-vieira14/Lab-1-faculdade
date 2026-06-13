#include <stdio.h>
void impnum(int num)
{
    //para resolvermos o problema do código 1, basta criar um laço verificando se a quantidade de digitos da variável pot é menor ou igual ao numero digitado. Caso for menor é adicionado um digito a mais na variável pot
    int pot = 10;
    while (pot <= num) {
        pot = pot * 10;
    }
    while (pot >= 10) {
        pot = pot / 10;
        putchar('0' + num / pot % 10);
    }
}
int main() {
    impnum(4526);
    impnum(45268);
}
