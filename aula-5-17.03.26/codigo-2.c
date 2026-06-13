#include <stdio.h>

void impnum(int num) {
    putchar('0' + num / 10); // imprime o 1
    putchar('0' + num % 10); // imprime o 2
}

void pulalinha() {
    putchar('\n');
}

int main() {
    impnum(12);
    // imprime o número "12" 
    pulalinha();
}