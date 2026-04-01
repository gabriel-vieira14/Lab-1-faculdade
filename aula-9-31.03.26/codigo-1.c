#include <stdio.h>
void impnum(int num) {
    int pot = 1000;
    while (pot >= 1) {
        putchar('0' + num / pot % 10);
        pot = pot / 10;
        putchar('\n');
    }
}
int main() {
    impnum(4526);

}
