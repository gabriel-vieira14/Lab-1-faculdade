#include <stdio.h>
void impnum(int num)
{
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