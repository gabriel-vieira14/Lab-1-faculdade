#include <stdio.h>

void impnum(int num) {
    putchar('0' + num);
}

void pulalinha() {
    putchar('\n');
}

int main() {
    impnum(12);
    // imprime o caractere "<" 
    pulalinha();
    impnum(1);
}