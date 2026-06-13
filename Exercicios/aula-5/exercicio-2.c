#include <stdio.h>
void impnum(int num) {
    if (num >= 2) {
        impnum(num / 2);
    }
    putchar('0' + num % 2);
}
int main() {
    impnum(10);
}